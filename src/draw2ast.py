from typing import List
import os
import sys
import subprocess

# $env:PATH += ";C:\Program Files\Graphviz\bin"


class Node:
    def __init__(self, val: str = "", children: List['Node'] = None):
        self.val = val
        self.children = children if children else []
        self.id_index = 0

syntax = []  # list? stack!
root = None
node_name_in_gv = 0

def parse(line: str) -> List[str]:
    return line.split()

def reduce(words: List[str]) -> None:
    global syntax
    parent = Node(words[0])
    for i in range(2, len(words)):
        parent.children.append(syntax.pop())
    parent.children.reverse()
    syntax.append(parent)

def read_file(file_name: str) -> None:
    global root, syntax
    with open(file_name, 'r', encoding='utf-8') as fin:
        for line in fin:
            line = line.strip()
            if not line:
                continue
            if "->" in line:
                words = parse(line)
                reduce(words)
                if words[0] == "Program":
                    root = syntax[-1]
            else:
                syntax.append(Node(line))

def traversal(dot: Node) -> None:
    global node_name_in_gv
    if not dot:
        return
    node_name_in_gv += 1
    dot.id_index = node_name_in_gv
    
    if dot.val.startswith('"'):
        tmpp = "\\" + dot.val
        tmpp = tmpp[:-1] + '\\"'
        dot.val = tmpp
    
    if dot.children:
        print(f'    {node_name_in_gv}[label="{dot.val}"];')
    else:
        print(f'    {node_name_in_gv}[label="{dot.val}",peripheries=2, style=filled, color="#eecc80"];')
    
    for child in dot.children:
        traversal(child)

def traversal_twice(dot: Node) -> None:
    if not dot:
        return
    for child in dot.children:
        print(f'    {dot.id_index} -> {child.id_index} ;')
        traversal_twice(child)

def print_output(file_out: str) -> None:
    global node_name_in_gv
    with open(file_out, 'w', encoding='utf-8') as f:
        original_stdout = sys.stdout
        os.sys.stdout = f
        
        print("digraph graphname {")
        traversal(root)
        node_name_in_gv = 0
        traversal_twice(root)
        print("}")
        
        os.sys.stdout = original_stdout

def main():
    file_name = "../output/helperOutput.txt"
    read_file(file_name)
    print_output("../output/ASTvis.gv")
    try:
        subprocess.run(['dot', '-Tpdf', "../output/ASTvis.gv", '-o', '../output/AST.pdf'], check=True)
        print("Successfully generated AST.pdf")
    except subprocess.CalledProcessError as e:
        print(f"Error generating PDF: {e}")
    except FileNotFoundError:
        print("Error: dot command not found. Please install Graphviz.")

if __name__ == "__main__":
    main()
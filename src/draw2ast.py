from typing import List
import os
import sys
import subprocess

# $env:PATH += ";C:\Program Files\Graphviz\bin"

"""
Node: 
    val: str
    children: List[Node]
    id_index: int
"""
class Node:
    def __init__(self, val: str = "", children: List['Node'] = None):
        self.val = val
        self.children = children if children else []
        self.id_index = 0

syntax = []  # list? stack!
root = None
node_name_in_gv = 0

# Split the line into words
def parse(line: str) -> List[str]:
    return line.split()

# define syntax,parent&children,and do some work to deal with words
def reduce(words: List[str]) -> None:
    global syntax
    parent = Node(words[0])
    for _ in range(2, len(words)):
        parent.children.append(syntax.pop())
    parent.children.reverse()
    syntax.append(parent)

# read the file and deal with different conditions
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
                # the Root!
                if words[0] == "Program":
                    root = syntax[-1]
            else:
                syntax.append(Node(line))

# DFS for Node
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
        if node_name_in_gv ==1:
            print(f'    {node_name_in_gv}[label="{dot.val}",peripheries=2,style=filled,color="#ee9c80"];')
        print(f'    {node_name_in_gv}[label="{dot.val}"]')
    else:
        print(f'    {node_name_in_gv}[label="{dot.val}",peripheries=2, style=filled, color="#80c2ee"];')
    
    for child in dot.children:
        traversal(child)

# DFS for edge
def traversal_twice(dot: Node) -> None:
    if not dot:
        return
    for child in dot.children:
        print(f'    {dot.id_index} -> {child.id_index} ;')
        traversal_twice(child)

# make it file_out(AST.gv)
def print_output(file_out: str) -> None:
    global node_name_in_gv
    with open(file_out, 'w', encoding='utf-8') as f:
        original_stdout = sys.stdout
        # stdout for f!
        os.sys.stdout = f  
        print("digraph AST {")
        traversal(root)
        node_name_in_gv = 0
        traversal_twice(root)
        print("}")
        
        os.sys.stdout = original_stdout

def main():
    file_name = "../output/helperOutput.txt"
    read_file(file_name)
    print_output("../output/AST.gv")
    try:
        subprocess.run(['dot', '-Tpdf', "../output/AST.gv", '-o', '../output/AST.pdf'], check=True)
        print("Successfully generated AST.pdf")
    except subprocess.CalledProcessError as e:
        print(f"Error generating PDF: {e}")
    except FileNotFoundError:
        print("Error: dot command not found. Please install Graphviz.")

if __name__ == "__main__":
    main()
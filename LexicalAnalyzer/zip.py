import os
import zipfile

def zip_folder(folder_path, output_path, exclude_patterns):
    with zipfile.ZipFile(output_path + '.zip', 'w', zipfile.ZIP_DEFLATED) as zipf:
        for root, dirs, files in os.walk(folder_path):
            for file in files:
                file_path = os.path.join(root, file)
                relative_path = os.path.relpath(file_path, folder_path)
                if not any(pattern in relative_path for pattern in exclude_patterns):
                    zipf.write(file_path, relative_path)
    print(f"Folder {folder_path} has been compressed {output_path}.zip")

if __name__ == "__main__":
    folder_path = "./"
    output_path = "./0221120281文天鑫"
    exclude_patterns = ['.vscode', '.gitignore', '.py','.zip']

    if os.path.isdir(folder_path):
        zip_folder(folder_path, output_path, exclude_patterns)
    else:
        print("Error! Folder not found.")
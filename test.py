import subprocess
import os
def send_command(command, redirect=None):
    if redirect != None:
        with open(redirect, "r") as input_file:
        # Run the command with input redirection
            result = subprocess.run(command, stdin=input_file, stdout=subprocess.PIPE, text=True)
    else:
       result = subprocess.run(command,stdout=subprocess.PIPE, text=True)

    print(command)
    return result.stdout
def get_filenames(folder_path):
  """
  Gets all filenames in a folder (including hidden files).

  Args:
      folder_path: The path to the folder.

  Returns:
      A list of filenames in the folder.
  """
  try:
    filenames = os.listdir(folder_path)
    return filenames
  except FileNotFoundError:
    print(f"Error: Folder not found: {folder_path}")
    return []


def main():
  
  """
  Prompts the user for terminal commands and executes them one by one.
  """
output = send_command(["gcc","-Wall", "-Wextra", "-O3", "-std=c99", "main.c", "-o", "main"])
#Example usage
folder_path = "Grafos/"
filenames = get_filenames(folder_path)
for filename in filenames:
    output = send_command(["touch", f"outs/{filename}"])
    output = send_command(["time", "./main"],f"Grafos/{filename}")
    if output:
      with open(f"outs/{filename}", "w") as text_file:
        text_file.write(output)


if __name__ == "__main__":
  main()

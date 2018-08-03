# this program probably works only on Linux.

import os

print('Enter the path of directory with cloned Git repositories.')
git_path = str(input('-> '))
git_repos = os.listdir(git_path)

for i in range(len(git_repos)):
    git_pull_path = str(git_path + '/' + git_repos[i])
    os.chdir(git_pull_path)
    print(git_repos[i])
    os.system('git pull')
    print()

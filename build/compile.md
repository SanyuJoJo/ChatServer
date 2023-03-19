cmake ..
make


/*
//将文件推送到github上
1. git status
2. git add .
3. git
4. git commit -m "第一次提交项目所有代码"
{
    配置账户
    git config --global user.name "SanyuJoJo"
    git config --global user.email "1600589524@qq.com"
    查看状态
    git config --list
    
    在本地生成密钥
    ssh-keygen -t rsa -C "1600589524@qq.com"
    进入ssh的目录，将自己的公钥配置在自己的github上，
    
    cd ~/.ssh/
    ~/.ssh$ ls
    id_rsa  id_rsa.pub  known_hosts
    ~/.ssh$ vim id_rsa.pub
    查看状态
    ssh git@github.com
}
5. git push origin master

//修改https协议为ssh
{
    1. git remote set-url origin git@github.com:username/repo.git
    2. git fetch
}

//文件更新
{
    如果你的文件有更改，想要更新到远程仓库，可以按照以下步骤操作：
    1.首先，使用以下命令查看你的本地Git仓库的状态：
    git status
    2.如果你已经进行了更改，并且想要将这些更改推送到远程仓库，可以使用以下命令：
    git add .
    这将将所有更改的文件添加到Git的暂存区。
    3.接下来，使用以下命令将更改提交到本地仓库：
    git commit -m "提交信息"
    4.最后，使用以下命令将更改推送到远程仓库：
    git push origin master
    这将把你的本地更改推送到名为"origin"的远程仓库的"master"分支上。
    现在，你的更改已经被更新到远程仓库了。
}
//更新到其他分支
{
    1.你可以使用git checkout命令来更新到其他分支，具体操作如下：

    2.使用git branch命令查看当前分支以及其他分支的列表，确定你想要切换的目标分支名称。

    3.使用git checkout命令，并指定目标分支名称，例如：
    git checkout target_branch_name
    这样就可以更新到目标分支。

    4.如果你在目标分支上修改了文件，你可以使用git add和git commit命令来提交更改。
    git add .
    git commit -m "update files"
    然后使用git push命令将本地更改推送到远程分支，例如：
    git push origin target_branch_name
    这样就完成了从当前分支更新到其他分支的操作。

}
//创建分支
{
    1. 首先，使用git branch命令查看当前分支以及其他分支的列表，确定你想要创建新分支的位置。

    2. 使用git branch命令，并指定新分支名称，例如：
    git branch new_branch_name
    这样就创建了一个名为new_branch_name的新分支，但是你还需要切换到该分支才能在该分支上进行操作。

    3. 使用git checkout命令并指定新分支名称来切换到新分支，例如：
    git checkout new_branch_name
    这样就可以切换到新分支并在该分支上进行操作了。

    4.如果你在新分支上修改了文件，你可以使用git add和git commit命令来提交更改。
    git add .
    git commit -m "update files"
    最后使用git push命令将新分支推送到远程分支，例如：
    git push origin new_branch_name
    这样就完成了创建新分支并将本地更改推送到远程分支的操作。

}
*/
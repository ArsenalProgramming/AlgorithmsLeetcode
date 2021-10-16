# AlgorithmsLearning

仓名：AlgorithmsLearning
<<<<<<< HEAD
=======

>>>>>>> dde0e471dedfa4fa70b2a9b55ae4ad6a9ab8598a

**1、一个标准的 README 应该包含哪些内容呢：**

![readme目录](https://user-images.githubusercontent.com/49310731/137573721-c8d73d01-5ee0-43f0-ad83-7006fbe65552.jpg)

- 项目背景
- 安装
- 使用
- Badge
- 相关项目（可选）
- 主要项目负责人
- 参与贡献方式
- 开源协议



**2、git简单用法：**

```bash
I.克隆分支：
git clone -b 分支名 url(克隆的地址)

II.进到本地下载目录：
cd 本地克隆的目录/

III.本地目录里打开git的命令窗口，执行以下命令：
（分别代表“目录里添加文件”、“注释”、“push到github分支”的意思）
git add .
git commit -m "上传改动注释说明"
git push origin wenzhi(本地分支名):wenzhi(远程分支名)

```

```bash
查看git版本

git --version

升级git版本
方法一： 官网重新下载最新git安装包，直接安装覆盖
方法二： cmd命令框中输入： git update-git-for-windows
```

```bash
查看git设置
git config --global
git config --global user.name "Arsenal-wenzhi"
git config --global user.email "2271034209@qq.com"

检查是否已生成密钥
cd ~/.ssh 或者cd C:\Users\用户名\.ssh
ls 如果有2个文件，则密钥已经生成，id_rsa.pub就是公钥

生成密钥
ssh-keygen -t rsa -C “2271034209@qq.com”
```

```bash
本地目录建仓

git init //把这个目录变成Git可以管理的仓库生成.git，代表是一个git目录
type null>.gitkeep // 生成.gitkeep，空文件夹上传用
git add README.md //文件添加到仓库 // 这个报错的？
git add . //不但可以跟单一文件，还可以跟通配符，更可以跟目录。一个点就把当前目录下所有未追踪的文件全部add了 
git commit -m "first commit" //把文件提交到仓库
git remote add origin git@github.com:wangjiax9/practice.git //关联远程仓库
git push -u origin master //把本地库的所有内容推送到远程库上
```



**3、github打不开解决方法：**

```bash
解决网址：https://www.jianshu.com/p/baf999efd45e
C:\Windows\System32\drivers\etc中的hosts文件，添加如下内容：
#github
140.82.112.4 github.com
199.232.69.194 github.global.ssl.fastly.net
185.199.108.153 assets-cdn.github.com
185.199.110.153 assets-cdn.github.com
185.199.111.153 assets-cdn.github.com
刷新DNS缓存
打开cmd窗口，执行ipconfig /flushdns命令
```



**4、建仓的目的：**刷题记录成长。

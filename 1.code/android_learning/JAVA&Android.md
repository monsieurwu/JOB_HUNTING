JAVA&Android

安卓推荐：

尚硅谷 安卓教程

天哥在奔跑 安卓开发教程

程序猿拉大锯 安卓开发自定义组件

动脑学院 kotlin

longway777 jetpack

学习路线：

java基础：韩顺平 900+节课

https://www.bilibili.com/video/BV1fh411y7R8/?spmid%20from=333.999.0.0&vd%20source=0a31e3f2c1721628014b2ea38c637e2c&vd_source=d31ec3e5b50ba0ea326786df2a78a612

尚硅谷：安卓

天哥在奔跑：安卓

https://www.bilibili.com/video/BV1Rt411e76H/?spm_id_from=333.337.search-card.all.click&vd_source=d31ec3e5b50ba0ea326786df2a78a612

longway777： jetpack（主流的开发框架 谷歌出的套件）

https://www.bilibili.com/video/BV1w4411t7UQ/?p=1&vd_source=0a31e3f2c1721628014b2ea38c637e2c



安卓基础：activity service provider

学好基础再学kotlin

安卓基础：

尚硅谷Android视频教程《15天精讲精练_参悟Android核心技术—上》

https://www.bilibili.com/video/BV1hW411L7CH/?spm_id_from=333.999.0.0

尚硅谷Android视频教程《15天精讲精练_参悟Android核心技术-中》

https://www.bilibili.com/video/BV1BW411L7QW/?spm_id_from=333.999.0.0&vd_source=d31ec3e5b50ba0ea326786df2a78a612

尚硅谷Android视频教程《15天精讲精练_参悟Android核心技术-下》

https://www.bilibili.com/video/BV1BW411L7th/?spm_id_from=333.999.0.0&vd_source=d31ec3e5b50ba0ea326786df2a78a612



chatgpt给的学习路线建议：

```
对于已经掌握C++和C的开发者来说，进入Android开发领域，建议的学习路径可以分为几个阶段：
1. Java基础
语言基础：学习Java的基本语法、数据类型、控制流程（条件判断、循环）、数组和字符串处理等。
面向对象编程：深入理解类与对象、继承、多态、接口、抽象类等OOP概念。
Java集合框架：熟悉使用List、Set、Map等集合类型，以及它们的实现和使用场景。
异常处理：学习Java的异常处理机制，了解如何抛出和捕获异常。
多线程编程：掌握Java中的多线程基础，包括创建线程、同步、线程池等。
Java新特性：了解Java 8及以后版本引入的新特性，如Lambda表达式、Stream API等。
2. Android基础
Android Studio和工具链：熟悉Android Studio的使用，了解Gradle构建系统。
Android应用架构：学习Android应用的基本组件（Activity、Service、Broadcast Receiver、Content Provider）和生命周期。
用户界面：掌握使用XML和Java/Kotlin构建用户界面，了解布局管理器、控件、事件处理等。
Intent和数据传递：理解Intent如何在不同组件间传递数据，实现应用内部和外部的交互。
数据存储：学习SharedPreferences、SQLite数据库和文件存储等本地数据存储方法。
网络通信：了解如何在Android应用中发起网络请求，处理JSON或XML数据。
3. 进阶学习
高级UI设计：深入学习自定义视图、动画、Material Design风格的组件等。
架构模式和最佳实践：了解MVVM、MVP等架构模式，学习如何构建可维护、可测试的应用。
安全性和性能优化：学习如何保证应用的安全性，以及如何诊断和优化Android应用的性能。
Kotlin：鉴于Kotlin现在是Android官方推荐的语言，可以考虑学习Kotlin，特别是它的协程处理并发编程。
4. 实践和构建项目
小项目实践：通过构建小型应用来实践所学知识，如天气应用、记账应用等。
开源项目贡献：参与开源项目可以让你了解实际项目的开发流程，提高解决问题的能力。
持续学习：技术是不断进步的，持续关注Android和Java生态的最新动态，适时学习新技术和工具。
```





## JAVA



## Android

先学个速成的 看个大概

### 7天Java0基础速成安卓开发

https://www.bilibili.com/video/BV1G7411t7zs/?spm_id_from=333.337.search-card.all.click&vd_source=d31ec3e5b50ba0ea326786df2a78a612

![image-20240308150008219](JAVA&Android.assets/image-20240308150008219.png)





#### 改ui为老的

设置里面

![image-20240322093709164](JAVA&Android.assets/image-20240322093709164.png)

#### 1.安卓怎么运行

学会看代码

app->manifests->AndroidManifest.xml

app的配置信息 比如icon app的图标 `android:icon="@mipmap/ic_launcher"`这是官方默认图标 在文件夹下：mipmap->ic_launcher 下面有很多图标 是为了适配不同手机像素 就有不同文件去适配

![image-20240308150753665](JAVA&Android.assets/image-20240308150753665.png)

下面这个就比较重要 相当于就是app里的界面

Main就是开机之后出现的第一个界面

后面会学怎么添加界面怎么添加界面的优先级

```java
        <activity
            android:name=".MainActivity"
            android:exported="true">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
```

![image-20240308153526688](JAVA&Android.assets/image-20240308153526688.png)

上面可以添加app用到的一些权限

比如 网络权限 获取网络状态 还有蓝牙 定位 总之这里就是放权限的

app->java->com.example.helloworld->MainActivity

这个是放界面控制区的

![image-20240308154057330](JAVA&Android.assets/image-20240308154057330.png)

MainActivity在app->res->layout下面有一个对应的文件<img src="JAVA&Android.assets/image-20240308154246138.png" alt="image-20240308154246138" style="zoom: 80%;" />

如果改MainActivity中的activity_main 然后按住alt+enter 就可以选create以创建新的xml文件

一般先用来进行界面初始化 控件初始化 初始化一些参数和变量 

不恰当比分 这里就类似于单片机的main函数  主要活动就是在这个文件里



![image-20240308154422220](JAVA&Android.assets/image-20240308154422220.png)

然后默认点ok就行

![image-20240308154901381](JAVA&Android.assets/image-20240308154901381.png)

之后在layout下就有一个新的文件了 这两个是一一对应的

MainActivity

```java
package com.example.helloworld;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {//这是安卓最底层的一个框架 MainActivity 依赖于 AppCompatActivity

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        //这是界面打开后 最先运行的地方
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);//对应界面ui
        //一般先用来运行界面初始化 控件初始化 初始化一些参数和变量
        //不恰当的比方 类似单片机的main函数
    }
}
```

在activity_main.xml布局文件中 可以看design和text 可以互相切换

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">
    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="match_parent">
        <TextView
            android:layout_width="wrap_content"
            android:text="hello"
            android:layout_height="wrap_content">

        </TextView>
        <Button
            android:layout_width="wrap_content"
            android:text="yes"
            android:background="@mipmap/ic_launcher"
            android:layout_height="wrap_content">

        </Button>

    </LinearLayout>



</androidx.constraintlayout.widget.ConstraintLayout>
```

constraintlayout：约束布局

LinearLayout：线性布局

match_parent：充满负控件

wrap_content：自适应

TextView：文字

Button：按钮

res里就是放资源的

drawable里放背景图 图标 以及自定义图标 布局文件

layout是放界面的布局文件和图标的

value放和布局相关的 和参数相关的

![image-20240308164207841](JAVA&Android.assets/image-20240308164207841.png)

最下面的Gradle是个很强大的东西 可以远程配置东西的



![image-20240308164234520](JAVA&Android.assets/image-20240308164234520.png)



build.gradle.kts

```kotlin
plugins {
    id("com.android.application")
}

android {//版本
    namespace = "com.example.helloworld"
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.helloworld"
        minSdk = 21
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
}

dependencies {//关联一些默认的文件

    implementation("androidx.appcompat:appcompat:1.6.1")
    implementation("com.google.android.material:material:1.11.0")
    implementation("androidx.constraintlayout:constraintlayout:2.1.4")
    testImplementation("junit:junit:4.13.2")
    androidTestImplementation("androidx.test.ext:junit:1.1.5")
    androidTestImplementation("androidx.test.espresso:espresso-core:3.5.1")
}
```

up主笔记

```java
第二节开始  目前Java0基础
第二节：
控件（常用的）：   控件（扩展）拖动条 进度条 浏览器框 地图 单选框 复选框
按钮 图片按钮
文本框
编辑框
图片框
选择开关
 wrap_content   自适应
 match_parent    充满父控件
 android:id="@+id/bt_1"   用来和JAVA文件通讯或者说是 绑定事件的
LinearLayout  线性布局
android:orientation="vertical"  设置布局方向  vertical垂直  horizontal水平
android:layout_margin="10dp"    边距

第三节开始   目前java 0基础
安卓开发  要多调试  多刷程序（因为你不知道你的APP程序会什么时候崩溃！！！！）
java里面的操作  大部分都类似于单片机的函数

控件的ID  是java文件与XML文件通讯的介质  类似于控件的 号码牌（唯一）
按钮：
单击事件有很多种实现方法  咱们讲最简单最常用的一种

按钮单机    用来发送命令控制硬件 例如：open door
文本框更新数据   用来接收硬件上报的传感器值  例如：温度 25.6


咱们 不凭空的学安卓开发  咱们是有目的的 直接面向项目和实战。
剩下的交给举一反三

第四节：MQTT Jar导入
复制粘贴！！！
Mqtt_init()
Mqtt_connect()
startReconnect()
爆红不用管！！！
最后赋值
Handler()
#################################
MQTT的知识  保证每个人都能连我的服务器   每个人的ID（MQTT要求唯一）都这设置为自己的QQ号
直接开搞  先跑起来 再讲原理
需要网络权限  和授权！（Android 6.0 以后需要动态授权后面再讲）
连接成功！
开始订阅 topic
拿到数据   想干嘛干嘛   随意做UI
下发控制
发布消息到指定 topic
拷贝发布函数
测试APP发消息  成功！！！
硬件  得到消息  判断 是不是“open_led ”然后 点灯！！
APP   得到消息  判断 传感器 数据  然后  UI展示   温度：56.3

剩下的  交给举一反三！！
```



#### 2.控件与界面布局

控件

res->layout->activity_main.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="match_parent">

        <TextView
            android:layout_width="56dp"
            android:layout_height="190dp"
            android:rotationX="2"
            android:text="hello">

        </TextView>

        <Button
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:background="@mipmap/ic_launcher"
            android:text="yes">

        </Button>

    </LinearLayout>


</androidx.constraintlayout.widget.ConstraintLayout>
```

![image-20240311155450869](JAVA&Android.assets/image-20240311155450869.png)

平常用的控件：按钮 图片按钮 选择开关 文本框 编辑框 图片框

java的注释跟c语言一样

控件：常用的
按钮 图片按钮

到阿里的图库去找ui下载png：https://www.iconfont.cn/

配色表：https://www.peisebiao.com/

准备一个文件夹去放ui

在Android开发中，"dp" 表示 "density-independent pixel"，即密度无关像素，它是一种用于描述屏幕上元素大小的单位。与像素（pixel）不同，dp 考虑了屏幕的密度，因此在不同密度的屏幕上，相同的 dp 值可以呈现相似大小的元素。

LinearLayout代表线性布局 这是最常用和最好用的一个布局方法

首先线性布局充满整个负控件的 其他布局都在线性布局里面

```java
    <LinearLayout
        android:layout_width="match_parent"
        android:orientation="vertical"
        android:gravity="center"
        android:layout_height="match_parent">
```

android:orientation="vertical"：设置布局方向 默认水平

android:gravity="center"设置居中



不要去拖动图标位置 使用代码来实现你想要的任何效果

```java
        <Button
            android:layout_width="40dp"
            android:layout_height="40dp"
            android:background="@drawable/open"
            android:text="yes"
            android:textColor="#ff2e63"
            android:layout_gravity="bottom"
            android:id="@+id/bt_1">

        </Button>
```

线性布局除了button 还可以放很多的东西

android:layout_gravity="bottom" 单独控制

带layout的就是用来控制布局的

id是用来和java文件通讯或者绑定的

文本框

```java
        <TextView
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:textSize="30sp"
            android:id="@+id/text_1"
            android:text="OH LA LA"/>
```

`> </Button>` 和 `/>`完全相等

编辑框

```java
        <EditText
            android:layout_width="wrap_content"
            android:hint="please input"
            android:layout_height="wrap_content"/>
```

android:hint:让用户输入

反正遇到什么就查 就百度 就chatgpt 属性什么的都可以查

图片框

```java
        <ImageView
            android:layout_width="wrap_content"
            android:src="@drawable/open"
            android:layout_height="wrap_content"/>
```

这个src用background也可以

选择开关

```java
 <SeekBar
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"/>
```

做一个这个界面

![image-20240312094706911](JAVA&Android.assets/image-20240312094706911.png)

![image-20240312094658285](JAVA&Android.assets/image-20240312094658285.png)

分界 就可以把它们分为很多liner_layout

![image-20240312095257847](JAVA&Android.assets/image-20240312095257847.png)

先搞懂线性布局 后面再讲相对布局

边距margin

```xml
<ImageView
                android:layout_width="wrap_content"
                android:layout_margin="10dp"
                android:src="@drawable/dolphin"
                android:layout_height="wrap_content"/>
```

可以做成轮播图的效果 网上有教程可以找找看怎么做

默认布局是水平 所以会一直往右排 改成垂直

```xml
android:orientation="vertical"
```

均分需要一个东西叫重心 当一个LinearLayout中的子视图都设置了`layout_weight`属性时，它们会按照权重来分配可用的空间。在这种情况下，`layout_weight`属性值越大，该视图占用的空间就越多。 例如，如果一个LinearLayout中有两个子视图，它们的`layout_weight`属性分别设置为1和2，那么第一个视图将占据1/3的可用空间，而第二个视图将占据2/3的可用空间。

```xml
android:layout_weight="1"
```

activity_main.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">


    <LinearLayout
        android:layout_width="match_parent"
        android:background="#e3fdfd"
        android:orientation="vertical"
        android:layout_height="match_parent">
        <LinearLayout
            android:layout_width="match_parent"
            android:background="#f6f6f6"

            android:layout_height="251dp">
            <ImageView
                android:layout_width="wrap_content"
                android:layout_margin="10dp"
                android:src="@drawable/dolphin"
                android:layout_height="wrap_content">

            </ImageView>

        </LinearLayout>

        <LinearLayout
            android:layout_width="match_parent"
            android:orientation="vertical"
            android:layout_marginTop="20dp"

            android:layout_height="wrap_content">
            <LinearLayout
                android:layout_width="match_parent"
                android:layout_height="wrap_content">
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:id="@+id/image_1"
                        android:layout_weight="1"
                        android:src="@drawable/light">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="开关">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/door_security">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="门禁">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/fan">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="风扇">

                    </TextView>

                </LinearLayout>



            </LinearLayout>
            <LinearLayout
                android:layout_width="match_parent"
                android:layout_marginTop="20dp"
                android:layout_height="wrap_content">
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/temp">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="温度">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/radar">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="雷达">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/pm">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="pm2.5">

                    </TextView>
                </LinearLayout>
            </LinearLayout>
            <Button
                android:layout_width="wrap_content"
                android:text="测试开关"
                android:id="@+id/btn_1"
                android:layout_height="wrap_content">

            </Button>
        </LinearLayout>
    </LinearLayout>

</androidx.constraintlayout.widget.ConstraintLayout>
```

后面讲事件和控件怎么绑定就也就这些控件 里面他们的id 怎么和java文件进行同步

#### 3.控件与界面通讯

控件的ID是java的文件与xml文件通讯的介质 类似于控件的号码牌（唯一）

常用控件：

按钮：按钮的单击事件

首先要先有一个id 才能来操作他

```xml
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:id="@+id/image_1"
                        android:layout_weight="1"
                        android:src="@drawable/light">

                    </ImageView>
```

在java这边就要绑定

```java
 image_1 = findViewById(R.id.image_1);
```

单机事件有很多种实现方法 讲最简单的 最常用的一种

java里面的操作 大部分都类似c的函数

安卓开发 要多调试 多刷程序 因为不知道你的app程序会什么时候崩溃



MainActivity.java

```java
package com.example.woowoowoo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Button btn_1; //类似单片机中初始化
    private ImageView image_1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn_1 = findViewById(R.id.btn_1); //寻找xml里面的id与自己定义的id进行绑定
        //然后就可以实现按钮的单击事件了
        //设置监听
        btn_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //这里就是单机之后 执行的地方
                System.out.println("hello");//java里面的debug日志打印
                //更直观的方法 用弹窗：toast
                //第一个参数 当前的界面 第二个参数 内容  第三个参数 显示的长度
                //在当前activity显示内容为hello的短时间弹窗
                Toast.makeText(MainActivity.this, "hello", Toast.LENGTH_SHORT).show();
            }
        });
        image_1 = findViewById(R.id.image_1);
        image_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "我是第一个图片", Toast.LENGTH_SHORT).show();

            }
        });




    }
}
```

效果：

点击按钮前

![image-20240312144105738](JAVA&Android.assets/image-20240312144105738.png)

点击按钮后：

![企业微信截图_20240312144203](JAVA&Android.assets/企业微信截图_20240312144203.png)



每按一下 下面的调试窗口就会显示一下

![image-20240312144846509](JAVA&Android.assets/image-20240312144846509.png)

然后就可以做前面几个图的事件了

实现点击图片 然后让下面的文字变化 实现模块联动

两个控件联动 ：单机按钮 更改textview的内容



`ui_init()`然后按alt+enter 就会创建方法

然后把初始化的东西都放到这个函数里 这样代码更整洁一些

```java
    private void ui_init() {
        btn_1 = findViewById(R.id.btn_1); //寻找xml里面的id与自己定义的id进行绑定
        image_1 = findViewById(R.id.image_1);
        text_test = findViewById(R.id.text_test);//实现绑定

    }
```

之后可以这么写 优化了更简洁一些 

现在还是可以按之前的 绑定 然后操作

MainActivity.java

```java
package com.example.woowoowoo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Button btn_1; //类似单片机中初始化
    private ImageView image_1;
    private TextView text_test;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ui_init();

        //然后就可以实现按钮的单击事件了
        //设置监听
        btn_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //这里就是单机之后 执行的地方
                System.out.println("hello");//java里面的debug日志打印
                //更直观的方法 用弹窗：toast
                //第一个参数 当前的界面 第二个参数 内容  第三个参数 显示的长度
                //在当前activity显示内容为hello的短时间弹窗
                Toast.makeText(MainActivity.this, "hello", Toast.LENGTH_SHORT).show();
            }
        });

        image_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "我是第一个图片", Toast.LENGTH_SHORT).show();
                //用到文本框的一个方法
                text_test.setText("我是新的内容");
            }
        });
    }

    private void ui_init() {
        btn_1 = findViewById(R.id.btn_1); //寻找xml里面的id与自己定义的id进行绑定
        image_1 = findViewById(R.id.image_1);
        text_test = findViewById(R.id.text_test);//实现绑定

    }
}
```

activity_main.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">


    <LinearLayout
        android:layout_width="match_parent"
        android:background="#e3fdfd"
        android:orientation="vertical"
        android:layout_height="match_parent">
        <LinearLayout
            android:layout_width="match_parent"
            android:background="#f6f6f6"

            android:layout_height="251dp">
            <ImageView
                android:layout_width="wrap_content"
                android:layout_margin="10dp"
                android:src="@drawable/dolphin"
                android:layout_height="wrap_content">

            </ImageView>

        </LinearLayout>

        <LinearLayout
            android:layout_width="match_parent"
            android:orientation="vertical"
            android:layout_marginTop="20dp"

            android:layout_height="wrap_content">
            <LinearLayout
                android:layout_width="match_parent"
                android:layout_height="wrap_content">
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:id="@+id/image_1"
                        android:layout_weight="1"
                        android:src="@drawable/light">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="开关">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/door_security">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="门禁">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/fan">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="风扇">

                    </TextView>

                </LinearLayout>



            </LinearLayout>
            <LinearLayout
                android:layout_width="match_parent"
                android:layout_marginTop="20dp"
                android:layout_height="wrap_content">
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/temp">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="温度">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/radar">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="雷达">

                    </TextView>

                </LinearLayout>
                <LinearLayout
                    android:layout_width="wrap_content"
                    android:orientation="vertical"
                    android:layout_height="wrap_content">
                    <ImageView
                        android:layout_width="140dp"
                        android:layout_height="100dp"
                        android:layout_weight="1"
                        android:src="@drawable/pm">

                    </ImageView>
                    <TextView
                        android:layout_width="wrap_content"
                        android:layout_gravity="center"
                        android:textSize="20sp"
                        android:layout_height="wrap_content"
                        android:text="pm2.5">

                    </TextView>
                </LinearLayout>
            </LinearLayout>
            <Button
                android:layout_width="wrap_content"
                android:text="测试开关"
                android:id="@+id/btn_1"
                android:layout_height="wrap_content">

            </Button>
            <TextView
                android:layout_width="wrap_content"
                android:text="我是原来的内容"
                android:id="@+id/text_test"
                android:layout_height="wrap_content">

            </TextView>
            
        </LinearLayout>
    </LinearLayout>

</androidx.constraintlayout.widget.ConstraintLayout>
```



后面要做的：

按钮单机用来发送命令控制硬件 例如：open door

文本框更新数据 用来接收硬件上报的传感器值 例如：温度 25.6

不凭空学安卓开发 而是有目的的直接面向项目实战

等学好 剩下的交给举一反三就可以了







按钮有很多属性







控件（扩展):浏览器框 地图 进度条 单选框  复选框



界面



![image-20240305170242795](JAVA&Android.assets/image-20240305170242795.png)

应用层开发的就是最上面那层 两个方向 要么一直在应用层 要么往下

![image-20240306093110579](JAVA&Android.assets/image-20240306093110579.png)





更新JDK

本地的jdk版本比代码需要的高，下载个低版本的就行

解决方法：File -> Settings -> Build, Execution, Deployment -> Build Tools -> Gradle

![img](JAVA&Android.assets/企业微信截图_17097144902.png)

点ok之后 先同步工程

![image-20240306104445869](JAVA&Android.assets/image-20240306104445869.png)

再编译

![img](JAVA&Android.assets/企业微信截图_17097146385119.png)

Android Studio中布局文件（如activity_main.xml）设计视图&代码视图相互切换

第一个安卓应用

- File->New->New Project

- empty views activity

- ![image-20240306111404990](JAVA&Android.assets/image-20240306111404990.png)

mainactivity.java

![image-20240306111544353](JAVA&Android.assets/image-20240306111544353.png)

`MainActivity.java` 是在使用 Java 语言开发 Android 应用程序时常见的一个类文件。在 Android 应用的开发中，它通常扮演着应用程序的入口点角色。每当你启动一个 Android 应用时，`MainActivity` 是首个被加载和执行的活动（Activity），负责创建和显示应用程序的主界面。

具体而言，`MainActivity.java` 的作用包括但不限于：

1. **初始化界面：** 它负责加载应用的布局资源（定义在 XML 文件中），并将其显示给用户。这包括设置应用的布局、初始化界面元素等。
2. **处理用户交互：** `MainActivity` 接收并处理来自用户的各种事件，如点击、触摸、键盘输入等。它包含了处理这些用户交互所需的逻辑代码。
3. **生命周期管理：** 在 Android 中，每个 Activity 都有自己的生命周期，`MainActivity` 通过重写生命周期回调方法（如 `onCreate()`, `onStart()`, `onResume()`, `onPause()`, `onStop()`, `onDestroy()` 等）来管理其生命周期，以确保应用的正确运行和资源管理。
4. **导航和管理：** `MainActivity` 可以启动其他的活动（Activities），处理数据传递，以及管理应用内的导航。
5. **集成服务和功能：** 它也可以初始化和集成各种服务和应用功能，比如访问网络数据、使用本地数据库、集成第三方库或服务等。

按住ctrl+鼠标左键 点 activity_main会跳转到activity_main.xml 可以显示代码或图

![image-20240306111925622](JAVA&Android.assets/image-20240306111925622.png)

然后就可以在text里更改显示的文字

然后起一个虚拟机运行即可

![image-20240306112136796](JAVA&Android.assets/image-20240306112136796.png)

安卓项目的目录结构需要深入了解



#### 4.导入物联网通讯的mqtt的jar包

![image-20240314161517673](JAVA&Android.assets/image-20240314161517673.png)

首先导入mqtt的jar包

之后除了mqtt的jar包可以导入 蓝牙的 各种都可以 就相当于c语言中的库 别人开发好了的 直接调用库就好了 

第五节课讲硬件 马上就能上手用

最后再讲handler和message这个多线程的东西

jar包下载地址：https://repo.eclipse.org/content/repositories/paho-releases/org/eclipse/paho/org.eclipse.paho.client.mqttv3/1.2.0/

用jar包有多种方式 这种是下载下来 还有一种是gradle 也有其他方法远程来下载

导入jar包 正常是在android 先切到Project 然后按下面的方式导入

粘贴到Project->app->lib

然后右键 add as library

放在app下面就可以了

之后就是学习怎么调用别人写好的

添加成功后就可以在这个文件下看到已经添加好了

![企业微信截图_20240314160345](JAVA&Android.assets/企业微信截图_20240314160345.png)

这个build.gradle就是用来配置一些插件 或者外置的库的 其实也可以直接添加地址 它会自动联网去下载（这个等下学下怎么导） 

然后就可以直接调用mqtt的这些函数 注意大写

注释 先选中要注释的行 然后按住ctrl+/ 就都能注释了

很多红的地方 按alt+enter就能解决 选择用安卓的还是java的库

复制粘贴就能解决大部分问题

权限放在manifest里面

![image-20240314160536801](JAVA&Android.assets/image-20240314160536801.png)

要加上这两个才有网络权限 和授权（android6.0以后需要动态授权 动态授权后面讲）

![image-20240314120920642](JAVA&Android.assets/image-20240314120920642.png)



新的变量设好

```java
    private ImageView image_1;//类似单片机中初始化
    private ImageView image_2;
//    private TextView text_test;
    private boolean isImage1 = true;
    private boolean isImage2 = true;
    private String host = "tcp://10.45.98.182:1883";
    private String userName = "android";
    private String passWord = "android";
    private String mqtt_id = "1045927662"; //定义成自己的QQ号  切记！不然会掉线！！！
    private String mqtt_sub_topic = "1045927662"; //为了保证你不受到别人的消息  订阅主题 得唯一
    private String mqtt_pub_topic = "1045927662_PC"; //为了保证你不受到别人的消息  哈哈  自己QQ好后面加 _PC
    private ScheduledExecutorService scheduler;
    private Handler handler;
    private MqttClient client;
    private MqttConnectOptions options;
```

mqtt初始化

```java
        private void Mqtt_init()
    {
        try {
            //host为主机名，test为clientid即连接MQTT的客户端ID，一般以客户端唯一标识符表示，MemoryPersistence设置clientid的保存形式，默认为以内存保存
            client = new MqttClient(host, mqtt_id,
                    new MemoryPersistence());
            //MQTT的连接设置
            options = new MqttConnectOptions();
            //设置是否清空session,这里如果设置为false表示服务器会保留客户端的连接记录，这里设置为true表示每次连接到服务器都以新的身份连接
            options.setCleanSession(false);
            //设置连接的用户名
            options.setUserName(userName);
            //设置连接的密码
            options.setPassword(passWord.toCharArray());
            // 设置超时时间 单位为秒
            options.setConnectionTimeout(10);
            // 设置会话心跳时间 单位为秒 服务器会每隔1.5*20秒的时间向客户端发送个消息判断客户端是否在线，但这个方法并没有重连的机制
            options.setKeepAliveInterval(20);
            //设置回调
            client.setCallback(new MqttCallback() {
                @Override
                public void connectionLost(Throwable cause) {
                    //连接丢失后，一般在这里面进行重连
                    System.out.println("connectionLost----------");
                    //startReconnect();
                }
                @Override
                public void deliveryComplete(IMqttDeliveryToken token) {
                    //publish后会执行到这里
                    System.out.println("deliveryComplete---------"
                            + token.isComplete());
                }
                @Override
                public void messageArrived(String topicName, MqttMessage message)
                        throws Exception {
                    //subscribe后得到的消息会执行到这里面
                    System.out.println("messageArrived----------");
                    Message msg = new Message();
                    msg.what = 3;   //收到消息标志位
                    msg.obj = topicName + "---" + message.toString();
                    handler.sendMessage(msg);    // hander 回传
                }
            });
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
```

mqtt连接服务器

```java
   private void Mqtt_connect() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    if(!(client.isConnected()) )  //如果还未连接
                    {
                        System.out.println("Mqtt_connect");//java里面的debug日志打印
                        client.connect(options);
                        Message msg = new Message();
                        msg.what = 31;
                        handler.sendMessage(msg);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    Message msg = new Message();
                    msg.what = 30;
                    handler.sendMessage(msg);
                }
            }
        }).start();
    }
```

mqtt重连

```java
 private void startReconnect() {
        scheduler = Executors.newSingleThreadScheduledExecutor();
        scheduler.scheduleAtFixedRate(new Runnable() {
            @Override
            public void run() {
                if (!client.isConnected()) {
                    System.out.println("startReconnect");//java里面的debug日志打印
                    Mqtt_connect();
                }
            }
        }, 0 * 1000, 10 * 1000, TimeUnit.MILLISECONDS);
    }
```

handler处理 注意 这个要写在onCreate里面 其他那些写在外面

```java
 handler = new Handler() {
            @SuppressLint("SetTextI18n")
            public void handleMessage(Message msg) {
                super.handleMessage(msg);
                switch (msg.what){
                    case 1: //开机校验更新回传
                        break;
                    case 2:  // 反馈回传

                        break;
                    case 3:  //MQTT 收到消息回传   UTF8Buffer msg=new UTF8Buffer(object.toString());
                        Toast.makeText(MainActivity.this,msg.obj.toString() ,Toast.LENGTH_SHORT).show();
                        //这一句就是把mqtt收到的消息打印出来

                        break;
                    case 30:  //连接失败
                        System.out.println("连接失败");//java里面的debug日志打印
                        Toast.makeText(MainActivity.this,"连接失败" ,Toast.LENGTH_SHORT).show();
                        break;
                    case 31:   //连接成功
                        System.out.println("连接成功");//java里面的debug日志打印
                        Toast.makeText(MainActivity.this,"连接成功" ,Toast.LENGTH_SHORT).show();
                        try {
                            client.subscribe(mqtt_sub_topic,1);//订阅
                        } catch (MqttException e) {
                            e.printStackTrace();
                        }
                        break;
                    default:
                        break;
                }
            }
        };
```

up主自己写的publish的函数 封装了一下publish

```java
 private void publishmessageplus(String topic,String message2)
    {
        if (client == null || !client.isConnected()) {
            return;
        }
        MqttMessage message = new MqttMessage();
        message.setPayload(message2.getBytes());
        try {
            client.publish(topic,message);
        } catch (MqttException e) {

            e.printStackTrace();
        }
    }
```



mqtt的知识 保证每个人都能连up主的服务器 每个人的ID都设置为自己的qq号 因为要唯一

连接成功后就订阅消息

拿到数据 想干嘛干嘛 随意做UI

下发控制

发布消息到指定topic

拷贝发布函数

测试app发消息 成功

剩下的交给举一反三

今天先实现功能 明天再讲原理

下节课讲handler和message 因为是联网的 联网一般就用到异步通信 多线程 

把代码调通

##### mqtt服务器搭建

服务器就启动了

![image-20240314134347990](JAVA&Android.assets/image-20240314134347990.png)

emqx的管理端口：http://localhost:18083/#/login?to=/dashboard/overview

![image-20240314134517707](JAVA&Android.assets/image-20240314134517707.png)

![image-20240314134537689](JAVA&Android.assets/image-20240314134537689.png)

修改了密码为：david96530

用本机地址也能连上：127.0.0.1:18083

测试一下这个服务器 能否实现主题发送与订阅

可以自测

![image-20240314142013238](JAVA&Android.assets/image-20240314142013238.png)

![image-20240314141337775](JAVA&Android.assets/image-20240314141337775.png)

订阅之后可以正常发送消息的话说明服务器没有问题了

![image-20240314141553651](JAVA&Android.assets/image-20240314141553651.png)

这个就说明搭建完成了 

把代码调通后就可以开始连接服务器

首先把ip地址改好 用主机的ipv4地址

```java
private String host = "tcp://10.45.98.182:1883";
```

一旦run程序 会自动连上服务器 服务器上就会显示



![image-20240314164513819](JAVA&Android.assets/image-20240314164513819.png)

并且手机上会显示连接成功  （但目前还是会先显示个连接失败）

![image-20240314170247834](JAVA&Android.assets/image-20240314170247834.png)

logcat也会打印

![image-20240314170348996](JAVA&Android.assets/image-20240314170348996.png)

本地下载使用mqtt.fx来发消息 设置里面可以写配置 用本地地址 端口是1883去connect

![image-20240314164923741](JAVA&Android.assets/image-20240314164923741.png)

![image-20240314164759647](JAVA&Android.assets/image-20240314164759647.png)

mqtt是即时通信

connect之后服务器

![image-20240314165232869](JAVA&Android.assets/image-20240314165232869.png)

然后就可以互相通信了

从mqtt.fx发送到手机

输入订阅主题 内容 然后就publish

![image-20240314165556933](JAVA&Android.assets/image-20240314165556933.png)

手机收到就说明通信成功

![image-20240314165656962](JAVA&Android.assets/image-20240314165656962.png)

然后设置一段代码 publish发给mqtt.fx

![image-20240314170730202](JAVA&Android.assets/image-20240314170730202.png)

加到点击的事件里

mqtt里订阅主题

![image-20240314170923310](JAVA&Android.assets/image-20240314170923310.png)

然后就点击事件 触发 

![企业微信截图_20240314171018](JAVA&Android.assets/企业微信截图_20240314171018.png)

能收到就说明两边是通的

![image-20240314172913985](JAVA&Android.assets/image-20240314172913985.png)

以项目为目的 这样更有兴趣 

![image-20240314172955025](JAVA&Android.assets/image-20240314172955025.png)

后续没有硬件 只能先暂停这个学习 收获还蛮大的



### 天哥在奔跑：安卓

https://www.bilibili.com/video/BV1Rt411e76H/?spm_id_from=333.337.search-card.all.click&vd_source=d31ec3e5b50ba0ea326786df2a78a612

安卓：

谷歌开发的操作系统

移动应用开发之一

最精简的开发流程

<img src="JAVA&Android.assets/image-20240315100335927.png" alt="image-20240315100335927" style="zoom:50%;" />

简书 天哥在奔跑

https://www.jianshu.com/u/2dcca6c67b84

gradle非常庞大 用到什么学什么就好

比较重要的几个文件

![image-20240315102416667](JAVA&Android.assets/image-20240315102416667.png)

![image-20240315102434046](JAVA&Android.assets/image-20240315102434046.png)

应用里用到的每一个activity都需要在这个manifest里面申明注册一下 才可以去调用 启动它

![image-20240315102830941](JAVA&Android.assets/image-20240315102830941.png)

![image-20240315103556660](JAVA&Android.assets/image-20240315103556660.png)

这个就是吧mainactivity设置为一个laucher 也就是把这个activity设置为main  然后把这个activity设置为启动的activity

mainactivity

![image-20240315102940697](JAVA&Android.assets/image-20240315102940697.png)

```java
package com.example.hello;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);//这个是布局代码
    }
}
```

![image-20240315103159376](JAVA&Android.assets/image-20240315103159376.png)

![image-20240315103300711](JAVA&Android.assets/image-20240315103300711.png)

一般用线性布局

《Android》项目目录结构解读：https://www.jianshu.com/p/f64a9bebaac3

好好熟悉一下目录结构

#### UI组件

线性布局 相对布局

##### 线性布局

https://www.jianshu.com/p/c9725d05a31d

![image-20240315104853005](JAVA&Android.assets/image-20240315104853005.png)

margin是外边距 padding是内边距

match_parent 匹配父控件 上一级宽度是多少 那空间就是多少

wrap_content：内容有多少 空间就多少

![image-20240315105742252](JAVA&Android.assets/image-20240315105742252.png)

让设置方向

安卓中 长度单位用dp 字体用sp

android:layout_weight="1" 把剩余内容按照权重去分配

如果要平分 那就把width设置为0

![image-20240315111635352](JAVA&Android.assets/image-20240315111635352.png)

只要是权重一样 就可以平分

练习方法：百度app画面 自己照着画 不一定达到那个效果 起码位置摆放正确

```xml
 <LinearLayout
        android:id="@+id/ll_1"
        android:layout_width="200dp"
        android:orientation="vertical"
        android:background="#000000"
        android:padding="20dp"
        android:paddingLeft="40dp"
        android:paddingBottom="100dp"
        


        android:layout_height="200dp">
        <View
            android:layout_width="match_parent"
            android:background="#FF0033"
            android:layout_height="match_parent">

        </View>

    </LinearLayout>
    <LinearLayout
        android:layout_width="match_parent"
        android:orientation="vertical"
        android:background="#0066FF"
        android:layout_marginTop="40dp"

        android:layout_height="match_parent">
        <View
            android:layout_width="100dp"
            android:background="#ffffff"
            android:layout_gravity="center"
            android:layout_weight="1"
            android:layout_height="100dp">

        </View>

    </LinearLayout>
```



##### 相对布局

https://www.jianshu.com/p/7ce3c29b7b71

<img src="JAVA&Android.assets/image-20240315113642140.png" alt="image-20240315113642140" style="zoom:67%;" />



toleftof 在...的左边

torightof 在...的右边

alignbottom 跟谁底部对齐

alignparentbottom跟父控件底部对齐

below 在...的下面

**ID 引用方式**：在 XML 中引用或定义一个 ID 时，如果是首次定义，应使用 `@+id/` 而不是 `@id/`。`@+id/` 是用来声明一个新的 ID 资源，而 `@id/` 是用于引用一个已经声明过的 ID。

```xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"

    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <View
        android:layout_width="100dp"
        android:id="@+id/view_1"
        android:background="#000000"

        android:layout_height="100dp">

    <View
        android:layout_width="100dp"
        android:id="@+id/view_2"
        android:background="#ff0033"
        android:layout_toRightOf="@id/view_1"
        android:layout_height="100dp">

    <View
        android:layout_width="100dp"
        android:id="@+id/view_3"
        android:background="#ff0033"
        android:layout_below="@id/view_1"
        android:layout_height="100dp">

    </View>

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="200dp"
        android:background="#0066ff"
        android:padding="15dp"
        android:layout_below="@id/view_3">
        <View
            android:layout_width="100dp"
            android:background="#ff0033"
            android:layout_height="match_parent">

        </View>
        <RelativeLayout
            android:layout_width="match_parent"
            android:background="#000000"
            android:padding="15dp"
            android:layout_height="match_parent">
            <View
                android:layout_width="100dp"
                android:id="@+id/view_4"
                android:background="#ff9900"
                android:layout_height="match_parent">

            </View>
            <View
                android:layout_width="100dp"
                android:id="@+id/view_5"
                android:background="#ff9900"
                android:layout_toRightOf="@id/view_4"
                android:layout_margin="10dp"
                android:layout_height="match_parent">

            </View>



        </RelativeLayout>
    </LinearLayout>

</RelativeLayout>
```







##### TextView组件

https://www.jianshu.com/p/8446725b587e

目标

文字大小、颜色
显示不下使用...
文字+icon
跑马灯
中划线、下划线

![image-20240315144617521](JAVA&Android.assets/image-20240315144617521.png)

Button一开始是红的 然后按alt+enter 上面会自动出现导入这个库 然后Button就不红了



![image-20240315145411510](JAVA&Android.assets/image-20240315145411510.png)

这是之前学过的的绑定 这行代码是在 Android 开发中用于绑定 XML 布局文件中定义的视图（View）到 Java 或 Kotlin 代码中的一个实例

返回值是View

![image-20240315145159938](JAVA&Android.assets/image-20240315145159938.png)

但这个 Button类

![image-20240315145229962](JAVA&Android.assets/image-20240315145229962.png)

于是要父类转子类(实践中会报错)

```java
mBtnTextView= this.<Button>findViewById(R.id.btn_textview);
```

![image-20240315152615324](JAVA&Android.assets/image-20240315152615324.png)

```java
package com.example.hello;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;



public class MainActivity extends AppCompatActivity {

    //布局里面有一个button 那我们首先要申明
    private Button mBtnTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mBtnTextView=findViewById(R.id.btn_textview);//绑定
        //然后再给button设置一个点击事件
        mBtnTextView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //跳转到TextView演示界面
                

            }
        });




    }
}
```

然后就可以新建一个activity

![image-20240315154607889](JAVA&Android.assets/image-20240315154607889.png)

之后textview的演示就写在这里面

![image-20240315154741138](JAVA&Android.assets/image-20240315154741138.png)

新建好了要在manifest里面去声明一下

![image-20240315154937225](JAVA&Android.assets/image-20240315154937225.png)

已经默认写好了

跳转 按ctrl+鼠标左键 跳转到TextViewActivity.java

```java
                Intent intent = new Intent(MainActivity.this, TextViewActivity.class);
                startActivity(intent);
```

修改这个新的activity的视图

View > TextView > Button 在这个类里 只有子类可以用父类的 而不能父类用子类的

这个地方如果定义类的时候设置为Button就会报错

![image-20240325140007568](JAVA&Android.assets/image-20240325140007568.png)

原因就是它是TextView类 不能往下设置



```java
package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;


import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn = findViewById(R.id.btn_textview);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, TextViewActivity.class);
                startActivity(intent);
            }
        });






    }
}
```



value中有个string 可以把一些文字 定义在这里面

![image-20240315160809019](JAVA&Android.assets/image-20240315160809019.png)

value/strings.xml

```xml
<resources>
    <string name="app_name">My Application</string>
    <string name="tv_test">woowoowoo is running</string>
</resources>
```



然后在视图里可能引用这里面定义的

![image-20240315160847689](JAVA&Android.assets/image-20240315160847689.png)

字体大小用sp为单位

放不下就变成...

![image-20240315161929583](JAVA&Android.assets/image-20240315161929583.png)

文字+icon

![image-20240315163045170](JAVA&Android.assets/image-20240315163045170.png)

跑马灯：通过java代码来实现

![image-20240315165051361](JAVA&Android.assets/image-20240315165051361.png)

但会有一点锯齿感

```java
      	mTv4.getPaint().setFlags(Paint.STRIKE_THRU_TEXT_FLAG);//穿过去的一根线 中划线
        mTv4.getPaint().setAntiAlias(true);//去掉锯齿
```

还可以通过html来显示

```java
        mTv6 = findViewById(R.id.tv_6);
        //类型转换
        mTv4.setText(Html.fromHtml("<u>呜呜呜在奔跑</u>"));//也是加下划线
```

最后是跑马灯

要有这个效果必须配单行形式的属性

```xml
        android:singleLine="true"
        android:ellipsize="marquee"
        android:marqueeRepeatLimit="marquee_forever"
```

必须设为焦点

```
        android:focusable="true"
        android:focusableInTouchMode="true"
```

##### Button

这其实是TextView的一个子类

<img src="JAVA&Android.assets/image-20240320135944215.png" alt="image-20240320135944215" style="zoom:67%;" />

这个用xml可以直接制作出来 不需要任何的图片

点击事件不仅可以button用 也可以text用 也可以给linerlayout一个点击事件 给view一个点击事件

在xml文件中先搞一个button

```xml
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:id="@+id/btn_button"
        android:text="Button"
        >
```

然后在MainActivity.java里面声明控件

```java
private  Button mBtnButton;
```

然后绑定控件

```java
mBtnButton=findViewById(R.id.btn_button);
```

然后类型转换 把这个转换成Button

新建一个activity

![image-20240320152843260](JAVA&Android.assets/image-20240320152843260.png)

新建的activity需要在manifest里面声明它

会自动声明 如果没有声明就要写一下  不然是无法跳转到这个activity的

![image-20240320153128946](JAVA&Android.assets/image-20240320153128946.png)

.ButtonActivity的意思是包名+.ButtonActivity 

跳转的地方就改成

```java
                Intent intent = new Intent(MainActivity.this, ButtonActivity.class);
                startActivity(intent);
```

这段代码的作用就是在`MainActivity`中启动一个新的活动`ButtonActivity`。

在drawable里面新建一个文件

![image-20240321163202315](JAVA&Android.assets/image-20240321163202315.png)



bg_btn.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<shape xmlns:android="http://schemas.android.com/apk/res/android"
    android:shape="rectangle">
    <solid
        android:color="#FF9900"/>
    <corners
        android:radius="10dp"/>

</shape>
```

用xml也可以设计图片 用于添加

当这个按钮被按压 会有颜色变化 没按压就保持原来的颜色

![image-20240321165125660](JAVA&Android.assets/image-20240321165125660.png)

把这个加到button的background就有按压效果了

drawable/bg_btn.xml

```
<?xml version="1.0" encoding="utf-8"?>
<selector xmlns:android="http://schemas.android.com/apk/res/android">
    <item android:state_pressed="true">
        <shape xmlns:android="http://schemas.android.com/apk/res/android"
            android:shape="rectangle">
            <solid
                android:color="#FF9900"/>
            <corners
                android:radius="10dp"/>

        </shape>

    </item>
    <item android:state_pressed="false">
        <shape>
            <solid android:color="#FF9900"/>
            <corners android:radius="5dp"/>

        </shape>

    </item>

</selector>
```

之后这个就可以当作属性添加到布局文件中

![image-20240325152954319](JAVA&Android.assets/image-20240325152954319.png)



点击事件

有两种方法

![image-20240321173856621](JAVA&Android.assets/image-20240321173856621.png)

一种是上面这种 在activity里面调用

另一种是在activity里面写方法 然后在xml里面调用

比如我在*activity_button.xml*里调用ButtonActivity.java里面的函数

![image-20240325160150225](JAVA&Android.assets/image-20240325160150225.png)

![image-20240325160132586](JAVA&Android.assets/image-20240325160132586.png)

activity_button.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"

    android:layout_width="match_parent"
    android:layout_height="match_parent">
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:background="@drawable/bg_btn"
        android:layout_marginTop="20dp"
        android:id="@+id/btn_button2"

        android:onClick="showToast"
        android:text="Button2"/>



</LinearLayout>
```

ButtonActivity.java

```java
package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class ButtonActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_button);
    }
    public void showToast(View view) {
        Toast.makeText(this,"clicked",Toast.LENGTH_SHORT).show();
        //在界面上弹出一个提示信息
    }




}
```





##### EditText控件

Button是Textview的一个子类

EditText也是Textview的一个子类

EditText是一个可以输入的一个控件

![image-20240322095331298](JAVA&Android.assets/image-20240322095331298.png)

登录界面：两个输入框+登录键

1.先声明控件

![image-20240325162108948](JAVA&Android.assets/image-20240325162108948.png)

2.找到控件

![image-20240325163408496](JAVA&Android.assets/image-20240325163408496.png)

3.设置它的点击事件

![image-20240325163744380](JAVA&Android.assets/image-20240325163744380.png)

4.新建一个activity

5.manifest里面添加上新的activity

6.在edittext activity的xml文件中写layout

```xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"

    android:layout_width="match_parent"
    android:padding="15dp"
    android:layout_height="match_parent">
    <EditText
        android:layout_width="match_parent"
        android:id="@+id/et_1"
        android:textSize="16sp"
        android:textColor="#FFAD33"
        android:hint="username"
        android:paddingLeft="20dp"
        android:paddingRight="10dp"
        android:drawableLeft="@drawable/user"
        
        android:maxLines="1"
        android:background="@drawable/bg_btn2"
        android:layout_height="50dp">

    </EditText>

    <EditText
        android:layout_width="match_parent"
        android:id="@+id/et_2"
        android:layout_below="@id/et_1"
        android:layout_marginTop="15dp"
        android:inputType="textPassword"
        android:drawableLeft="@drawable/password"
        android:maxLines="1"
        android:textSize="20sp"
        android:textColor="#FFAD33"

        android:hint="password"
        android:layout_height="50dp">

    </EditText>
    <EditText
        android:layout_width="match_parent"
        android:id="@+id/et_3"
        android:layout_below="@id/et_2"
        android:textSize="16sp"
        android:textColor="#FFAD33"
        android:hint="phone number"
        android:inputType="number"
        android:layout_height="50dp">

    </EditText>
    <Button
        android:layout_width="match_parent"
        android:id="@+id/btn_login"
        android:background="@drawable/bg_btn"
        android:layout_marginTop="20dp"
        android:layout_below="@id/et_3"
        android:text="Log in"
        android:textColor="#fff"
        android:textSize="20dp"
        android:layout_height="50dp">

    </Button>

</RelativeLayout>
```

加圆角的background

bg_btn2.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<shape xmlns:android="http://schemas.android.com/apk/res/android">
    <stroke
        android:width="2dp"
        android:color="#999999"/>
    <corners
        android:radius="5dp"/>

</shape>
```

![image-20240326093731647](JAVA&Android.assets/image-20240326093731647.png)

监听输入内容

1.声明控件

![image-20240326095901312](JAVA&Android.assets/image-20240326095901312.png)

2.找到控件

![image-20240326100037888](JAVA&Android.assets/image-20240326100037888.png)

3.设置事件

![image-20240326100442124](JAVA&Android.assets/image-20240326100442124.png)

分别是文字改变之前 之中 之后

CharSequence s中的s就是当前 输入框里面的内容 我们可以把它打印出来

在logcat里就能监听到输入内容

EditTextActivity.java

```java
package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class EditTextActivity extends AppCompatActivity {
    private Button mBtnLogin;
    private EditText mEtUserName;
    private EditText mEtPassWord;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_text);

        mBtnLogin = findViewById(R.id.btn_login);
        mBtnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(EditTextActivity.this, "login in success", Toast.LENGTH_SHORT).show();
            }
        });
        mEtUserName = findViewById(R.id.et_1);
        //使用代码动态调整图标大小
        Drawable drawable = ContextCompat.getDrawable(this, R.drawable.user);
        if (drawable != null) {
            drawable.setBounds(0, 0, 60, 60); // 设置图标大小
            mEtUserName.setCompoundDrawables(drawable, null, null, null);
        }
        mEtUserName.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                Log.d("editted",s.toString());

            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });
        mEtPassWord = findViewById(R.id.et_2);
        Drawable drawable2 = ContextCompat.getDrawable(this, R.drawable.password);
        if (drawable != null) {
            drawable.setBounds(0, 0, 60, 60); // 设置图标大小
            mEtPassWord.setCompoundDrawables(drawable, null, null, null);
        }


    }
}
```

![企业微信截图_20240326110010](JAVA&Android.assets/企业微信截图_20240326110010.png)

##### Radio Button

一组里面单选 就用这个

![image-20240326110335261](JAVA&Android.assets/image-20240326110335261.png)

通过调用函数来实现之前的功能

TextViewActivity.java

```java
package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Paint;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class TextViewActivity extends AppCompatActivity {
    private TextView mTv4;
    private Button mBtnButton;
    private Button mBtmEditButton;
    private Button mBtnRadioButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_text_view);
        mTv4 = findViewById(R.id.tv_3);
        mTv4.getPaint().setFlags(Paint.STRIKE_THRU_TEXT_FLAG);
        mTv4.getPaint().setAntiAlias(true);

        mBtnButton = findViewById(R.id.btn_button);
        mBtmEditButton = findViewById(R.id.btn_button3);
        mBtnRadioButton = findViewById(R.id.btn_radiobutton);
        setListeners();
    }

    //再写一个监听器
    private void setListeners(){
        OnClick onClick = new OnClick();
        mBtnButton.setOnClickListener(onClick);
        mBtmEditButton.setOnClickListener(onClick);
        mBtnRadioButton.setOnClickListener(onClick);
    }

    //写一个类 实现调用一个接口
    private class OnClick implements View.OnClickListener{

        @Override
        public void onClick(View v) {
            Intent intent = null;
            int viewId = v.getId();

            if (viewId == R.id.btn_button) {
                intent = new Intent(TextViewActivity.this, ButtonActivity.class);
            } else if (viewId == R.id.btn_button3) {
                intent = new Intent(TextViewActivity.this, EditTextActivity.class);
            } else if (viewId == R.id.btn_radiobutton) {
                intent = new Intent(TextViewActivity.this, RadioButtonActivity.class);
            }

            startActivity(intent);
        }
    }

}
```

开始设计radiobutton

activity_radio_button.xml

```xml
    <RadioButton
        android:layout_width="wrap_content"
        android:id="@+id/rb_1"
        android:text="男"
        android:textSize="18sp"
        android:textColor="#FF6600"
        android:layout_height="wrap_content">

    </RadioButton>
```

![image-20240326143819313](JAVA&Android.assets/image-20240326143819313.png)

做一个选择男或者女的 结合radio group来使用 选中男就不会选中女 因为他们在一个组里面

activity_radio_button.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"

    android:layout_width="match_parent"
    android:padding="15dp"
    android:layout_height="match_parent">
    <RadioGroup
        android:id="@+id/rg_1"
        android:layout_width="wrap_content"
        android:orientation="vertical"
        android:layout_height="wrap_content">
        <RadioButton
            android:layout_width="wrap_content"
            android:id="@+id/rb_1"
            android:text="男"
            android:textSize="18sp"
            android:textColor="#FF6600"
            android:layout_height="wrap_content">

        </RadioButton>
        <RadioButton
            android:layout_width="wrap_content"
            android:id="@+id/rb_2"
            android:text="女"
            android:textSize="18sp"
            android:textColor="#FF6600"
            android:layout_height="wrap_content">

        </RadioButton>
    </RadioGroup>
    

</RelativeLayout>
```

可以加默认选项

activity_radio_button.xml

```xml
 <RadioButton
            android:layout_width="wrap_content"
            android:id="@+id/rb_1"
            android:text="男"
            android:checked="true"
            android:textSize="18sp"
            android:textColor="#FF6600"
            android:layout_height="wrap_content">

        </RadioButton>
```

注意：radiobutton一定要加id 否则就失效了

设置监听事件

1.使用控件前 先声明控件

![image-20240326153028155](JAVA&Android.assets/image-20240326153028155.png)

2. 找到控件

   ![image-20240326153240691](JAVA&Android.assets/image-20240326153240691.png)

3.设置事件

效果：发生变化的时候触发监听事件

RadioButtonActivity.java

```java
package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class RadioButtonActivity extends AppCompatActivity {
    private RadioGroup mRg1;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_radio_button);
        mRg1 = (RadioGroup) findViewById(R.id.rg_1);
        mRg1.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                RadioButton radioButton = group.findViewById(checkedId);
                Toast.makeText(RadioButtonActivity.this, radioButton.getText(), Toast.LENGTH_SHORT).show();
            }
        });



    }
}
```

##### 复选框checkbox

![image-20240326163501351](JAVA&Android.assets/image-20240326163501351.png)

可以选择多个 并且选择后再选一下 可以取消选择

CheckBoxActivity.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"

    android:layout_width="match_parent"
    android:padding="15dp"
    android:layout_height="match_parent">
    <TextView
        android:layout_width="wrap_content"
        android:text="what system do you use?"
        android:textSize="20sp"
        android:id="@+id/tv_1"
        android:layout_marginBottom="10dp"

        android:layout_height="wrap_content">



    </TextView>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_1"
        android:layout_below="@id/tv_1"
        android:text="Android"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_2"
        android:layout_below="@id/cb_1"
        android:text="Linux"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_3"
        android:layout_below="@id/cb_2"
        android:text="ios"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_4"
        android:layout_below="@id/cb_3"
        android:text="Windows"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>

</RelativeLayout>
```

![image-20240326170157231](JAVA&Android.assets/image-20240326170157231.png)

设置状态发生变化的发生事件

1.声明控件

![image-20240326170451325](JAVA&Android.assets/image-20240326170451325.png)

2.找到控件

![image-20240326171104080](JAVA&Android.assets/image-20240326171104080.png)

3.写方法

![image-20240326171126095](JAVA&Android.assets/image-20240326171126095.png)

CheckBoxActivity.java

```java
package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.Toast;

public class CheckBoxActivity extends AppCompatActivity {
    private CheckBox mCb1, mCb2, mCb3, mCb4;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_check_box);
        mCb1 = findViewById(R.id.cb_1);
        mCb2 = findViewById(R.id.cb_2);
        mCb3 = findViewById(R.id.cb_3);
        mCb4 = findViewById(R.id.cb_4);
        mCb1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Toast.makeText(CheckBoxActivity.this, isChecked?"Android选中":"Android选中未选中", Toast.LENGTH_SHORT).show();
            }
        });
        mCb2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Toast.makeText(CheckBoxActivity.this, isChecked?"Linux选中":"Linux未选中", Toast.LENGTH_SHORT).show();
            }
        });
        mCb3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Toast.makeText(CheckBoxActivity.this, isChecked?"ios选中":"ios未选中", Toast.LENGTH_SHORT).show();
            }
        });
        mCb4.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Toast.makeText(CheckBoxActivity.this, isChecked?"Windows选中":"Windows未选中", Toast.LENGTH_SHORT).show();
            }
        });


    }
}
```

activity_check_box.xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"

    android:layout_width="match_parent"
    android:padding="15dp"
    android:layout_height="match_parent">
    <TextView
        android:layout_width="wrap_content"
        android:text="what system do you use?"
        android:textSize="20sp"
        android:id="@+id/tv_1"
        android:layout_marginBottom="10dp"

        android:layout_height="wrap_content">



    </TextView>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_1"
        android:layout_below="@id/tv_1"
        android:text="Android"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_2"
        android:layout_below="@id/cb_1"
        android:text="Linux"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_3"
        android:layout_below="@id/cb_2"
        android:text="ios"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>
    <CheckBox
        android:layout_width="wrap_content"
        android:id="@+id/cb_4"
        android:layout_below="@id/cb_3"
        android:text="Windows"
        android:textSize="20sp"

        android:layout_height="wrap_content">

    </CheckBox>

</RelativeLayout>
```

# Android

> 比特猫编程

### Button的3种方法

1.onClick属性

![image-20241028172135227](JAVA&Android.assets/image-20241028172135227.png)

![image-20241028172159598](JAVA&Android.assets/image-20241028172159598.png)

就在布局中onClick调用一个方法 然后在java文件里把方法写出来

2.setOnClickListener匿名内部类

![image-20241028172523668](JAVA&Android.assets/image-20241028172523668.png)

![image-20241028172554739](JAVA&Android.assets/image-20241028172554739.png)

绑定控件的id， 然后设置匿名内部类 在里面设计一个点击的方法

3.Activity实现OnClickListener接口

绑定控件id 然后调用接口（自己是线下这个接口）

![image-20241028172640193](JAVA&Android.assets/image-20241028172640193.png)

![image-20241028172727108](JAVA&Android.assets/image-20241028172727108.png)

用第三个理论上可以设个switch但一直在case提示报错

可以用else if写

![image-20241029142108845](JAVA&Android.assets/image-20241029142108845.png)

创建的时候需要重写这个方法

![image-20241104120030083](JAVA&Android.assets/image-20241104120030083.png)







### EditText输入框获取输入框内容

![image-20241028173131649](JAVA&Android.assets/image-20241028173131649.png)

![image-20241028173339165](JAVA&Android.assets/image-20241028173339165.png)

### 单选框（RadioButton/RadioGroup）

![image-20241029120015773](JAVA&Android.assets/image-20241029120015773.png)

![image-20241029120202257](JAVA&Android.assets/image-20241029120202257.png)

### 复选框(CheckBox)

![image-20241029120312095](JAVA&Android.assets/image-20241029120312095.png)

![image-20241029120412100](JAVA&Android.assets/image-20241029120412100.png)

### Toast使用

之前button的时候讲过

ctrl+p可以看这个方法的使用方法

![image-20241029145729971](JAVA&Android.assets/image-20241029145729971.png)



```java
Toast.makeText(this, "click me", Toast.LENGTH_SHORT).show();
```

LENGTH_SHORT表示显示短时间 可以换位LENGTH_LONG

最后的show是显示的方法



### Listview优化前后代码

```java
        public View getView(int position, View convertView, ViewGroup parent) {
//            View view = View.inflate(MainActivity.this, R.layout.item_list, null);
//
//            ImageView iv_icon = view.findViewById(R.id.iv);
//            TextView tv_title = view.findViewById(R.id.title);
//            TextView tv_price = view.findViewById(R.id.tv_price);
//            TextView price = view.findViewById(R.id.price);
//
//            iv_icon.setImageResource(icons[position]);
//            tv_title.setText(titles[position]);
//            return view;

            VH holder;
            if (convertView == null) { //判断是否为null
                convertView = View.inflate(MainActivity.this, R.layout.item_list, null);
//                ImageView iv_icon = view.findViewById(R.id.iv);
//                TextView tv_title = view.findViewById(R.id.title);
//                TextView tv_price = view.findViewById(R.id.tv_price);
                holder = new VH();
//                holder.iv_icon = iv_icon;
//                holder.tv_title = tv_title;
//                holder.tv_price = tv_price;
                holder.iv_icon = convertView.findViewById(R.id.iv);
                holder.tv_title = convertView.findViewById(R.id.title);
                holder.tv_price = convertView.findViewById(R.id.tv_price);
                convertView.setTag(holder);
            } else {
                holder = (VH)convertView.getTag();
            }

            holder.iv_icon.setImageResource(icons[position]);
            holder.tv_title.setText(titles[position]);
            holder.tv_price.setText(prices[position]);


            return convertView;
        }
    }

    class VH{
        ImageView iv_icon;
        TextView tv_title;
        TextView tv_price;
    }
```



### 底部导航栏

![image-20241106103155465](JAVA&Android.assets/image-20241106103155465.png)

知识点：

权重

属性说明：

- app:itemBackground 设置背景
- app:itemTextColor 设置文字颜色
- app:itemIconTint 设置图标颜色
- app:labelVisibilityMode 设置标签的显示模式
- app:menu 设置导航栏菜单内容
- app:itemActiveIndicatorStyle  设置选中的指示器的样式 ，设置为@null可以去掉默认样式

>  buttom_navigation_menu.xml

![image-20241106103750749](JAVA&Android.assets/image-20241106103750749.png)

> colors.xml

![image-20241106104021558](JAVA&Android.assets/image-20241106104021558.png)

> color_bottom_bar.xml

![image-20241106104046445](JAVA&Android.assets/image-20241106104046445.png)

颜色选择器 选中就变色



### logcat缩略模式

![image-20241106104317670](JAVA&Android.assets/image-20241106104317670.png)

![image-20241106104330829](JAVA&Android.assets/image-20241106104330829.png)

### 

### AlertDialog 对话框

普通对话框

确保布局文件中有触发 `showNormalDialog` 方法的控件（例如按钮），并且绑定了该方法。

![image-20241126172051875](JAVA&Android.assets/image-20241126172051875.png)

![image-20241126172130170](JAVA&Android.assets/image-20241126172130170.png)

单选对话框

![image-20241126180922067](JAVA&Android.assets/image-20241126180922067.png)

![image-20241126180956064](JAVA&Android.assets/image-20241126180956064.png)

![image-20241126181112223](JAVA&Android.assets/image-20241126181112223.png)



注意：`.setSingleChoiceItems(titleArr, index, new DialogInterface.OnClickListener()`这个地方把第二个参数换为index而不是0的好处是 可以记住上一次选择的是哪一个选项



#### 多选对话框

![image-20241127102626063](JAVA&Android.assets/image-20241127102626063.png)

![image-20241127103424413](JAVA&Android.assets/image-20241127103424413.png)

![image-20241127103443720](JAVA&Android.assets/image-20241127103443720.png)

注意：`checkedArr = new boolean[]{false, false, false, false, false};`这一行是为了让第二个打开的时候不要继续记住上一次多选的信息 把记录清空



自定义对话框

![image-20241127121349284](JAVA&Android.assets/image-20241127121349284.png)

![image-20241127121440602](JAVA&Android.assets/image-20241127121440602.png)

这个dialog的layout需要自己在创建

![image-20241127121826896](JAVA&Android.assets/image-20241127121826896.png)

### ListView

1.定义listview

![image-20241202132118279](JAVA&Android.assets/image-20241202132118279.png)

2.准备数据

![image-20241202132205731](JAVA&Android.assets/image-20241202132205731.png)

3.创建adapter 实现四个方法

![image-20241202132254383](JAVA&Android.assets/image-20241202132254383.png)

重点是getView这个方法

在layout里面创建item_list 然后才能加载 一个一个item要怎么布置 左边图片 右边title和价格

![image-20241202150311139](JAVA&Android.assets/image-20241202150311139.png)



4.关联listview和adapter

先初始化listview 然后使用其中的一个方法叫setAdapter 然后需要传入一个adapter 我们就创建一个adapter



![image-20241202132411767](JAVA&Android.assets/image-20241202132411767.png)

这样就完成了一个listview



简单来说：

1.定义listview

2.准备数据

3.创建adapter 实现四个方法

4.关联listview和adapter



#### listview优化

原因：

> 1.为什么需要优化？
>
> - 因为在滑动的过程中，会不断地创建item对象，滑入屏幕的item被创建，滑出屏幕的item对象被销毁，快速滑动，就会不停地创建对象，销毁对象，就造成卡顿
> - 不停地findViewById也会消耗性能 
>
> 2.如何优化  通过viewHolder类缓存item

```java
getView(int position, View convertView, ViewGroup parent)
● position：当前数据项的位置
● convertView：可复用的视图对象，用于优化列表的性能
● parent：父级视图组，即 ListView 或 GridView
```

使用convertView来做优化

创建一个类

![image-20241202142850020](JAVA&Android.assets/image-20241202142850020.png)

然后改一下getView

![image-20241202143006072](JAVA&Android.assets/image-20241202143006072.png)

之所以需要MyViewHolder这个类 是因为我们需要减少findViewById 我们把控件缓存到vh中

通过convertView.setTag(vh)把vh放到这个convertView当中

然后只要convertView不为null  我们就直接`vh = (MyViewHolder)convertView.getTag();`把这个holder取出来

直接使用它的数据 不需要继续findViewById 从而提高它的性能



listview点击事件

- setOnItemClickListener 单击事件
- setOnItemLongClickListener 长按事件

![image-20241202145512705](JAVA&Android.assets/image-20241202145512705.png)



![image-20250207172841960](JAVA&Android.assets/image-20250207172841960.png)





### RecyclerView

```
为什么使用 RecyclerView 代替 ListView？
性能：RecyclerView 提供了更好的视图复用和内存管理。
灵活的布局管理：支持多种布局，满足不同的显示需求。
动画支持：内置的动画支持使得数据变动时的用户体验更加流畅。
更强的交互性：支持拖动、滑动删除等高级交互。
多类型视图支持：能方便地处理多种类型的列表项。
懒加载和分页：更易于实现懒加载、分页等功能。
现代化的设计：符合现代 Android UI 设计趋势和标准。
```



![image-20241206171102438](JAVA&Android.assets/image-20241206171102438.png)

![image-20241206171130411](JAVA&Android.assets/image-20241206171130411.png)

如果要把垂直改为水平

```java
 listRv.setLayoutManager(new LinearLayoutManager(this, LinearLayout.HORIZONTAL, false)); //设置方向为水平
```



![image-20241206171159112](JAVA&Android.assets/image-20241206171159112.png)



### Activity

模板创建

![image-20241210110020736](JAVA&Android.assets/image-20241210110020736.png)

加载布局：

在onCreate方法中，调用setContentView加载布局文件

```java
@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);//加载布局
}
```

AndroidManifest配置

在清单文件的application节点下配置：

<activity android:name="com.example.activity.ActivityB" />

![image-20241210110244543](JAVA&Android.assets/image-20241210110244543.png)



横屏不销毁 就配置manifest这个

![image-20241209160355186](JAVA&Android.assets/image-20241209160355186.png)

intent filter来决定那个activity启动

![image-20241209162038317](JAVA&Android.assets/image-20241209162038317.png)

 配置页面的屏幕方向

固定横屏：android:screenOrientation="landscape"

固定竖屏：android:screenOrientation="portrait"

![image-20241210110444819](JAVA&Android.assets/image-20241210110444819.png)

页面跳转

可以通过点击去触发

```java
//启动
Intent intent = new Intent(context,目标Activity.class)
startActivity(intent)
    
//关闭
finish()
```

![image-20241210110730190](JAVA&Android.assets/image-20241210110730190.png)

关闭

![image-20241210110751659](JAVA&Android.assets/image-20241210110751659.png)



生命周期

```
Activity生周期方法：
● onCreate  被创建
● onStart 即将可见
● onResume 可见可交互(有焦点)
● onPause 可见但失去焦点(不可交互)
● onStop 不可见  onRestart
● onDestroy 被销毁
● onRestart 重新可见
```

![image-20241210110932165](JAVA&Android.assets/image-20241210110932165.png)

intent跳转淘宝

![image-20241210111034202](JAVA&Android.assets/image-20241210111034202.png)



activity跳转传参

有两种方式：

- intent.putExtra
- Bundle

发送

![image-20241210111107209](JAVA&Android.assets/image-20241210111107209.png)

接受

![image-20241210111324506](JAVA&Android.assets/image-20241210111324506.png)

发送

![image-20241210111121049](JAVA&Android.assets/image-20241210111121049.png)

接收

![image-20241210111412858](JAVA&Android.assets/image-20241210111412858.png)



activity数据回传

第一步：A页面跳转页面使用startActivityForResult

![image-20241210111459537](JAVA&Android.assets/image-20241210111459537.png)

第二步：B页面返回的时候调用setResult

![image-20241210111640976](JAVA&Android.assets/image-20241210111640976.png)

第三步：A页面重写onActivityResult

![image-20241210111716288](JAVA&Android.assets/image-20241210111716288.png)

这里我们判断requestCode为100，则知道是从B页面返回的，即可从而取出回传的数据

底部导航栏

写布局文件

![image-20241210115643659](JAVA&Android.assets/image-20241210115643659.png)

![image-20241210115713149](JAVA&Android.assets/image-20241210115713149.png)

写一个menu的

![image-20241210115741982](JAVA&Android.assets/image-20241210115741982.png)



固定底部

所有都显示出来 之前必须点了 才能显示出来

```
app:labelVisibilityMode="labeled"
```

![image-20241210115447031](JAVA&Android.assets/image-20241210115447031.png)



颜色选择器

可以给文字和图标改颜色

![image-20241210120517120](JAVA&Android.assets/image-20241210120517120.png)

![image-20241210120645619](JAVA&Android.assets/image-20241210120645619.png)

去掉药丸

![image-20241210120822363](JAVA&Android.assets/image-20241210120822363.png)

有很多方法可以去掉 可以改gradle版本 可以用java代码 最简单的就是在布局文件把这个属性取消

![image-20241210121426345](JAVA&Android.assets/image-20241210121426345.png)

![image-20241210121441013](JAVA&Android.assets/image-20241210121441013.png)

有很多方法可以去掉 可以改gradle版本 可以用java代码 最简单的就是在布局文件把这个属性取消



### fragment

![image-20241210112123963](JAVA&Android.assets/image-20241210112123963.png)

这种就可以用fragment做

把每个模块的显示内容进行封装 模块化思想

可以嵌入activity 可以构建更灵活的界面

Fragment加载：有两种方式，动态加载和静态加载

- 静态加载：在activity的布局中添加fragment(了解) 

  就是在activity的布局文件中直接写fragment的控件

  ![image-20241210113008393](JAVA&Android.assets/image-20241210113008393.png)



- 动态加载：在Activity中动态加载fragment(重点)动态加载（这个比较常用）：

1. 创建 Fragment 类： 

- - 创建一个继承自 `androidx.fragment.app.Fragment` 的子类。
  - 在 Fragment 类中实现 `onCreateView` 方法，该方法用于创建 Fragment 的视图。

2. 布局文件： 

- - 创建一个 XML 布局文件，用于定义 Fragment 的界面布局。

3. 在 Activity 中使用 Fragment： 

- - 在 Activity 的布局文件中添加一个用于显示 Fragment 的容器，例如一个 `FrameLayout`。
  - 在 Activity 的代码中使用 `FragmentManager` 在适当的位置加载和管理 Fragment





![image-20241210121900159](JAVA&Android.assets/image-20241210121900159.png)



### 微信底部导航栏实战

首先 创建包

![image-20241210134606455](JAVA&Android.assets/image-20241210134606455.png)

![image-20241210134630978](JAVA&Android.assets/image-20241210134630978.png)

创建空的fragment

![image-20241210134748634](JAVA&Android.assets/image-20241210134748634.png)

只用把这个留下来就可以

![image-20241210134909695](JAVA&Android.assets/image-20241210134909695.png)

然后就把这个复制成四个

![image-20241210135239570](JAVA&Android.assets/image-20241210135239570.png)

layout也复制一下

改下这个fragment的布局

![image-20241210135725905](JAVA&Android.assets/image-20241210135725905.png)

然后就建一个list 把fragment都放到里面

![image-20241210140915286](JAVA&Android.assets/image-20241210140915286.png)

![image-20241210141158056](JAVA&Android.assets/image-20241210141158056.png)

然后编写一个方法 来显示fragment

![image-20241210141544186](JAVA&Android.assets/image-20241210141544186.png)

container是帧布局的id

![image-20241210141627628](JAVA&Android.assets/image-20241210141627628.png)

打开首先是显示首页

![image-20241210142618758](JAVA&Android.assets/image-20241210142618758.png)

第0个位置

![image-20241210144243211](JAVA&Android.assets/image-20241210144243211.png)

![image-20241210144339262](JAVA&Android.assets/image-20241210144339262.png)

## 数据存储

### 内部存储

- 存储数据 openFileOutput
- 读取数据 openFileInput

```java
 public void write_inner(View view) throws IOException {
        FileOutputStream fos = openFileOutput("data.txt", MODE_PRIVATE);
        fos.write("比特猫编程666777".getBytes());
        fos.close();
        Toast.makeText(this, "写入数据成功", Toast.LENGTH_SHORT).show();
    }

    public void read_inner(View view) throws IOException {
        FileInputStream fis = openFileInput("data.txt");
        byte[] bytes = new byte[fis.available()];
        fis.read(bytes);
        Toast.makeText(this, new String(bytes), Toast.LENGTH_SHORT).show();
        fis.close();
    }
```

做2个button 然后去写这两个button的onclick点击事件



### 外部存储

将应用的targetSdk版本改为22

![image-20241216201125365](JAVA&Android.assets/image-20241216201125365.png)

并配置权限

![image-20241216201221584](JAVA&Android.assets/image-20241216201221584.png)

搞两个点击事件 一个读一个写 判断一下挂载

![image-20241216201253736](JAVA&Android.assets/image-20241216201253736.png)

判断的是 **外部存储设备** 是否已正确挂载并且可以访问

###  sqlite

**第一步：创建数据库帮助类**

![image-20241219115926779](JAVA&Android.assets/image-20241219115926779.png)

初始化

![image-20241219115946473](JAVA&Android.assets/image-20241219115946473.png)

数据库操作：增删改查

- **插入 insert()**

![image-20241219120016037](JAVA&Android.assets/image-20241219120016037.png)

- **查询  query()**

![image-20241219120027532](JAVA&Android.assets/image-20241219120027532.png)

- **更新 update()**

![image-20241219120037092](JAVA&Android.assets/image-20241219120037092.png)

- **删除 delete()**

![image-20241219120108969](JAVA&Android.assets/image-20241219120108969.png)

`findAll(null)` 只是为了调用 `findAll` 方法来更新用户列表视图，并且由于 `findAll` 的参数 `view` 没有在方法内使用，因此你可以安全地传入 `null`。

根据名字查找

![image-20241219120124281](JAVA&Android.assets/image-20241219120124281.png)



### 使用binding

`View Binding` 是一种新的方式，Android 提供的现代化 API，目的是通过生成一个类来帮助我们更方便、更安全地访问视图元素。使用 View Binding 不再需要手动调用 `findViewById`，而是直接通过自动生成的绑定类来引用视图元素。

#### 启用 View Binding：

1. 开启 View Binding：

   - 在 `build.gradle` 文件中开启 View Binding。

   ```
       buildFeatures {
           viewBinding true
       }
   ```
   
   ![image-20241219141129306](JAVA&Android.assets/image-20241219141129306.png)

2. **通过绑定类获取控件：** Android Studio 会根据布局文件生成一个与布局对应的 Binding 类，可以通过它来访问控件。

#### 例子（使用 View Binding）：

```java
javaCopy Codeimport com.example.sqlitelearning.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // 使用 View Binding 绑定布局
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        
        // 使用 binding 访问控件
        binding.nameEt.setText("John Doe");
        binding.phoneEt.setText("1234567890");
    }
}
```

nameEt和phoneEt就是控件id

### 项目：记事本

1. 功能介绍

- 记事本应用界面的首页是一个内容列表和一个添加按钮。
- 长按item：列表长按时会弹出一个对话框，询问是否删除。点击确定，删除item
- 点击item：跳转详情，可修改记录
- 添加按钮：添加一条记录



先把数据库做好 

#### 创建各种包

先创建一下

![image-20241219145433272](JAVA&Android.assets/image-20241219145433272.png)

![image-20241219145450232](JAVA&Android.assets/image-20241219145450232.png)

adapter 继承类

bean 实体类

db 数据库

ui

utils

![image-20241219145649659](JAVA&Android.assets/image-20241219145649659.png)![image-20241219145704912](JAVA&Android.assets/image-20241219145704912.png)

![image-20241219145723579](JAVA&Android.assets/image-20241219145723579.png)

小结：

1. **adapter**: 用于处理 UI 层的数据与视图的绑定。
2. **bean**: 用于表示数据模型的实体类。
3. **db**: 数据库相关的操作类和接口。
4. **ui**: 用户界面相关的文件，包括 Activity、Fragment、布局文件等。
5. **utils**: 工具类，用于封装常见的辅助功能。

#### 时间处理工具类

![image-20241223095018080](JAVA&Android.assets/image-20241223095018080.png)

#### 设计实体类

设置setter getter

在bean包右键写一个Notepad的class

写好实体类后

![image-20241219144957632](JAVA&Android.assets/image-20241219144957632.png)

右键选择generate

![image-20241219145034616](JAVA&Android.assets/image-20241219145034616.png)

选择

![image-20241219145056815](JAVA&Android.assets/image-20241219145056815.png)

全选 然后点ok

![image-20241219145148128](JAVA&Android.assets/image-20241219145148128.png)

这样就设置好了

#### 创建数据库帮助类

![image-20241219174603891](JAVA&Android.assets/image-20241219174603891.png)

#### 通过点击事件跳转到编写页面

![image-20241223090521727](JAVA&Android.assets/image-20241223090521727.png)

#### 设计edit页面的layout

一个返回键 一个title 一个输入框 一个保存 一个删除

![image-20241223090634998](JAVA&Android.assets/image-20241223090634998.png)

这里只用到insert 之后会继续写 比如findall delete之类的方法

![image-20241219154859876](JAVA&Android.assets/image-20241219154859876.png)

就会变成这样

![image-20241219154922131](JAVA&Android.assets/image-20241219154922131.png)

返回键 ----> finish

标题 ---> binding.titleTv.setText("添加记录");

删除 ---> binding.delete.setOnClickListener(v -> binding.contentEt.setText(""));

保存 ---> 调用数据库

![image-20241223092742936](JAVA&Android.assets/image-20241223092742936.png)

首先得到content

```java
String content = binding.contentEt.getText().toString().trim();
```

Notepad实例化 并把数据(内容和时间)放到notepad中

```java
				Notepad notepad = new Notepad();
                notepad.setContent(content);
                notepad.setTime(TimeUtil.getTime());
```

数据库也需要初始化

![image-20241224112031124](JAVA&Android.assets/image-20241224112031124.png)

数据库中没有insert就重写一下

```java
    public void insert(Notepad notepad) {
        String sql = "insert into notepad(content,time) values(?,?)";
        SQLiteDatabase db = getWritableDatabase();
        db.execSQL(sql,new String[]{notepad.getContent(),notepad.getTime()});
    }
```

![image-20241224112104010](JAVA&Android.assets/image-20241224112104010.png)

在初始化`myDbHelper = new MyDbHelper(this);`的时候有报错 因为定义的时候要把后面的删掉 不用什么参数都传入

![image-20241224112300494](JAVA&Android.assets/image-20241224112300494.png)

#### activity_main展示列表

![image-20241223093828570](JAVA&Android.assets/image-20241223093828570.png)

item_list在layout里设计一下

![image-20241223094731618](JAVA&Android.assets/image-20241223094731618.png)

![image-20241223094833816](JAVA&Android.assets/image-20241223094833816.png)

使用tools而不使用android是因为这里的数据是从数据库来 这里的文字只有在预览时有效 在实际中不会使用到这个文字

![image-20241220103451857](JAVA&Android.assets/image-20241220103451857.png)

![image-20241220103958668](JAVA&Android.assets/image-20241220103958668.png)

#### 设计recyclerview显示

准备NotepadListAdapter的类

1.添加组件

2.准备数据

3.Adapter准备

相关方法说明

- onCreateViewHolder 创建viewHolder
- onBindViewHolder 绑定viewHolder数据
- getItemCount  设置列表条数

![image-20241223095826481](JAVA&Android.assets/image-20241223095826481.png)

```
方法之间的关系
onCreateViewHolder 创建视图。
onBindViewHolder 为创建好的视图绑定数据。
getItemCount 告诉 RecyclerView 子项数量，影响创建和绑定的总次数。
```

#### 创建adapter

设计好后在main activity中创建recyclerview的adapter

在mainactivity里同时也初始化数据库

![image-20241224122830854](JAVA&Android.assets/image-20241224122830854.png)

![image-20241223101600274](JAVA&Android.assets/image-20241223101600274.png)

在数据库实现findAll

![image-20241224121417197](JAVA&Android.assets/image-20241224121417197.png)

实现适配器的update的

![image-20241224121320824](JAVA&Android.assets/image-20241224121320824.png)

#### 设置列表分割线

![image-20241223102132757](JAVA&Android.assets/image-20241223102132757.png)

#### 长按删除功能

![image-20241223102338897](JAVA&Android.assets/image-20241223102338897.png)

![image-20241223163722018](JAVA&Android.assets/image-20241223163722018.png)

写一下showDeleteDialog这个函数 传入v.getContext()

直接把之前对话框的代码复制一下

![image-20241223163803355](JAVA&Android.assets/image-20241223163803355.png)

把mainactivity的数据库申明改为public

![image-20241224143130720](JAVA&Android.assets/image-20241224143130720.png)

数据库中实现一下delete这个方法

![image-20241223164650373](JAVA&Android.assets/image-20241223164650373.png)

dbhelper需要改为public 我们在adapter中才能拿到

![image-20241223105240256](JAVA&Android.assets/image-20241223105240256.png)



抽取findAll这个方法 因为总会用到（快捷键ctrl+alt+m）

![image-20241223164735435](JAVA&Android.assets/image-20241223164735435.png)

需要把NotepadListAdapter的申明放在最上面 以便各个方法都能用![img]()

![image-20241224143825461](JAVA&Android.assets/image-20241224143825461.png)

然后把findAll的类型改为public 这样在适配器里才能调用

![image-20241224144006321](JAVA&Android.assets/image-20241224144006321.png)



#### 通知首页刷新

之前数据保存后 数据库的数据更新了 但返回首页 发现首页的并没有更新 

![image-20241223165050573](JAVA&Android.assets/image-20241223165050573.png)

第二种方式：

跳转到新增页面，我们采用startActivityForResult，并传递一个code 100

![image-20241223165218365](JAVA&Android.assets/image-20241223165218365.png)

在首页，重写onActivityResult，判断requestCode和resultCode，满足条件，调用findAll重新查询最新数据并更新页面

![image-20241223165259283](JAVA&Android.assets/image-20241223165259283.png)



要加序列化才能putextra数据进去

#### 编辑记录

Serializable序列化

![image-20241223165416895](JAVA&Android.assets/image-20241223165416895.png)

携帶數據

![image-20241223165511628](JAVA&Android.assets/image-20241223165511628.png)

接收数据



判斷是新增還是修改

![image-20241224160952349](JAVA&Android.assets/image-20241224160952349.png)

如果是点击适配器跳转过来 那serializable里面有内容 会吧内容打印到文本框里

然后如果是点击 + 过来 则会serializable==null



保存数据库时也需要判断

![image-20241223165901278](JAVA&Android.assets/image-20241223165901278.png)

实现一下数据库的update

![image-20241223165939060](JAVA&Android.assets/image-20241223165939060.png)



![image-20241223170812373](JAVA&Android.assets/image-20241223170812373.png)

Bug处理

写完后一直有新增内容无法刷新主页的问题

查看数据库是没有问题的 数据有正常加载

然后就开始加日志

![image-20241225094422175](JAVA&Android.assets/image-20241225094422175.png)

![image-20241225094442480](JAVA&Android.assets/image-20241225094442480.png)

发现新增内容的返回值resultcode一直是0 正常应该是-1

知识点：

```
onActivityResult代码执行有两个条件：
1. 跳转是通过startActivityForResult
2. 关闭页面的时候需要使用setResult
```

最后发现 问题出现在点击跳转的时候

![image-20241225094717866](JAVA&Android.assets/image-20241225094717866.png)

一开始使用的是startactivity

所以新增的情况 自然不会回resultcode


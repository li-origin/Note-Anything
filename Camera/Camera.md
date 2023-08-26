# Camera

> [相机成相之像距、物距、焦距](http://www.4k8k.xyz/article/u012572552/109694172)

perfetto:
1、进程都是以占用排名的

自动对焦(AutoFocus):
https://zhuanlan.zhihu.com/p/109000056
http://www.exclusivearchitecture.com/?page_id=980
https://photographylife.com/how-phase-detection-autofocus-works
https://photography.tutsplus.com/tutorials/understand-how-autofocus-works-part-2--photo-13757
https://zhuanlan.zhihu.com/p/20726158
https://weibo.com/2424567755/IgxZwwneN?type=comment#_rnd1625646209151

稳定性：
adb shell dumpsys activity oom| grep "ADJ"
////下面列出了内存查杀的优先级，0之前的都是系统级别的
(base) lhl@:~/Working_directory/JIRA/M2/Alpha_Blending/10.26/new$ adb shell dumpsys activity oom| grep "ADJ"
-900: SYSTEM_ADJ (   73,728K)
-800: PERSISTENT_PROC_ADJ (   73,728K)
-700: PERSISTENT_SERVICE_ADJ (   73,728K)
0: FOREGROUND_APP_ADJ (   73,728K)
100: VISIBLE_APP_ADJ (   92,160K)
200: PERCEPTIBLE_APP_ADJ (  110,592K)
225: PERCEPTIBLE_MEDIUM_APP_ADJ (  129,024K)
250: PERCEPTIBLE_LOW_APP_ADJ (  129,024K)
300: BACKUP_APP_ADJ (  221,184K)
400: HEAVY_WEIGHT_APP_ADJ (  221,184K)
500: SERVICE_ADJ (  221,184K)
600: HOME_APP_ADJ (  221,184K)
700: PREVIOUS_APP_ADJ (  221,184K)
800: SERVICE_B_ADJ (  221,184K)
900: CACHED_APP_MIN_ADJ (  221,184K)
999: CACHED_APP_MAX_ADJ (  322,560K)
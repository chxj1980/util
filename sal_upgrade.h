#ifndef __SAL_UPGRADE_H__
#define __SAL_UPGRADE_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#include "sal_standard.h"

typedef struct version_s
{
    int bUpdate;       //是否需要升级
    char local[256];   //当前的使用版本
    char remote[256];  //服务器的最新版本
}version_s;

/*
 函 数 名: sal_upgrade_init
 功能描述: 初始化升级模块
 输入参数: 无
 输出参数: 无
 返 回 值: 成功返回0,失败返回小于0
*/
int sal_upgrade_init();

/*
 函 数 名: sal_upgrade_exit
 功能描述: 去初始化升级模块
 输入参数: 无
 输出参数: 无
 返 回 值: 成功返回0,失败返回小于0
*/
int sal_upgrade_exit();

/*
 函 数 名: sal_upgrade_check
 功能描述: 获取服务器最新版本信息，外部阻塞调用
 输入参数: urlCfg 升级配置文件的下载链接
            timeout 超时时间，单位毫秒
 输出参数: version_info 输出相关版本信息
 返 回 值: 成功返回0,失败返回小于0
*/
int sal_upgrade_check(char* urlCfg, int timeout, version_s* version_info);

/*
 函 数 名: sal_upgrade_enable
 功能描述: 使能升级功能，根据得到的升级配置信息进行升级操作
 输入参数: enable 0 不使能，1使能
 输出参数: 无
 返 回 值: 成功返回0,失败返回小于0
*/
int sal_upgrade_enable(int enable);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif


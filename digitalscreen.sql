/*
 Navicat Premium Data Transfer

 Source Server         : mysql
 Source Server Type    : MySQL
 Source Server Version : 80033
 Source Host           : localhost:3306
 Source Schema         : digitalscreen

 Target Server Type    : MySQL
 Target Server Version : 80033
 File Encoding         : 65001

 Date: 06/03/2024 10:58:41
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for lib_book
-- ----------------------------
DROP TABLE IF EXISTS `lib_book`;
CREATE TABLE `lib_book`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `title` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `desc` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `download` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `wacth` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `img` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `type` int NULL DEFAULT NULL,
  `link` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lib_book
-- ----------------------------

-- ----------------------------
-- Table structure for lib_course
-- ----------------------------
DROP TABLE IF EXISTS `lib_course`;
CREATE TABLE `lib_course`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `title` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `subtitle` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `desc` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `img` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `watch` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `link` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `type` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 3 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lib_course
-- ----------------------------
INSERT INTO `lib_course` VALUES (3, '先进制造工程训练', '湖南大学 王群', '6章 30节', '1701516018196.jpg', '734', 'https://www.icourse163.org/course/HNU-1206459828', 0);

-- ----------------------------
-- Table structure for lib_forum
-- ----------------------------
DROP TABLE IF EXISTS `lib_forum`;
CREATE TABLE `lib_forum`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `title` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `subtitle` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `watch` int(10) UNSIGNED ZEROFILL NULL DEFAULT NULL,
  `like` int(10) UNSIGNED ZEROFILL NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lib_forum
-- ----------------------------

-- ----------------------------
-- Table structure for lib_learningstyle
-- ----------------------------
DROP TABLE IF EXISTS `lib_learningstyle`;
CREATE TABLE `lib_learningstyle`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `question` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `options` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lib_learningstyle
-- ----------------------------

-- ----------------------------
-- Table structure for lib_question
-- ----------------------------
DROP TABLE IF EXISTS `lib_question`;
CREATE TABLE `lib_question`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `question` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `options` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `img` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `watch` int NULL DEFAULT NULL,
  `type` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lib_question
-- ----------------------------

-- ----------------------------
-- Table structure for rel_course_knowledge
-- ----------------------------
DROP TABLE IF EXISTS `rel_course_knowledge`;
CREATE TABLE `rel_course_knowledge`  (
  `id` int NOT NULL,
  `course_id` int NULL DEFAULT NULL,
  `knowledge_id` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_course_knowledge
-- ----------------------------

-- ----------------------------
-- Table structure for rel_course_task
-- ----------------------------
DROP TABLE IF EXISTS `rel_course_task`;
CREATE TABLE `rel_course_task`  (
  `id` int NOT NULL,
  `course_id` int NULL DEFAULT NULL,
  `task_id` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_course_task
-- ----------------------------

-- ----------------------------
-- Table structure for rel_course_user
-- ----------------------------
DROP TABLE IF EXISTS `rel_course_user`;
CREATE TABLE `rel_course_user`  (
  `id` int NOT NULL,
  `course_id` int NULL DEFAULT NULL,
  `user_id` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_course_user
-- ----------------------------

-- ----------------------------
-- Table structure for rel_group_user
-- ----------------------------
DROP TABLE IF EXISTS `rel_group_user`;
CREATE TABLE `rel_group_user`  (
  `id` int NOT NULL,
  `group_id` int NOT NULL,
  `user_id` int NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_group_user
-- ----------------------------

-- ----------------------------
-- Table structure for rel_subgroup_task
-- ----------------------------
DROP TABLE IF EXISTS `rel_subgroup_task`;
CREATE TABLE `rel_subgroup_task`  (
  `id` int NOT NULL,
  `subgroup_id` int NOT NULL,
  `task_id` int NOT NULL,
  `start_week` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `end_week` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `start_time` datetime NULL DEFAULT NULL,
  `end_time` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_subgroup_task
-- ----------------------------

-- ----------------------------
-- Table structure for rel_subgroup_task_submit
-- ----------------------------
DROP TABLE IF EXISTS `rel_subgroup_task_submit`;
CREATE TABLE `rel_subgroup_task_submit`  (
  `id` int NOT NULL,
  `subgroup_id` int NOT NULL,
  `task_id` int NOT NULL,
  `submit_time` datetime NULL DEFAULT NULL,
  `status` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `message` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_subgroup_task_submit
-- ----------------------------

-- ----------------------------
-- Table structure for rel_subgroup_user
-- ----------------------------
DROP TABLE IF EXISTS `rel_subgroup_user`;
CREATE TABLE `rel_subgroup_user`  (
  `id` int NOT NULL,
  `subgroup_id` int NULL DEFAULT NULL,
  `user_id` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_subgroup_user
-- ----------------------------

-- ----------------------------
-- Table structure for rel_task_knowledge
-- ----------------------------
DROP TABLE IF EXISTS `rel_task_knowledge`;
CREATE TABLE `rel_task_knowledge`  (
  `id` int NOT NULL,
  `task_id` int NOT NULL,
  `knowledge_id` int NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_task_knowledge
-- ----------------------------

-- ----------------------------
-- Table structure for rel_user_menu
-- ----------------------------
DROP TABLE IF EXISTS `rel_user_menu`;
CREATE TABLE `rel_user_menu`  (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `user_id` bigint NOT NULL,
  `menu_id` bigint NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rel_user_menu
-- ----------------------------

-- ----------------------------
-- Table structure for sys_clockin
-- ----------------------------
DROP TABLE IF EXISTS `sys_clockin`;
CREATE TABLE `sys_clockin`  (
  `id` int NOT NULL,
  `user_id` int NOT NULL,
  `clock_in_time` datetime NOT NULL,
  `task_id` int NOT NULL,
  `week` int NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_clockin
-- ----------------------------

-- ----------------------------
-- Table structure for sys_clockout
-- ----------------------------
DROP TABLE IF EXISTS `sys_clockout`;
CREATE TABLE `sys_clockout`  (
  `id` int NOT NULL,
  `user_id` int NOT NULL,
  `clock_in_time` datetime NOT NULL,
  `task_id` int NOT NULL,
  `week` int NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_clockout
-- ----------------------------

-- ----------------------------
-- Table structure for sys_experiment
-- ----------------------------
DROP TABLE IF EXISTS `sys_experiment`;
CREATE TABLE `sys_experiment`  (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `exp_name` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `exp_name`(`exp_name`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_experiment
-- ----------------------------
INSERT INTO `sys_experiment` VALUES (3, '仿真');
INSERT INTO `sys_experiment` VALUES (5, '图像处理');
INSERT INTO `sys_experiment` VALUES (1, '测绘');
INSERT INTO `sys_experiment` VALUES (2, '让电机动起来');
INSERT INTO `sys_experiment` VALUES (6, '软件开发');
INSERT INTO `sys_experiment` VALUES (4, '运动编程');

-- ----------------------------
-- Table structure for sys_group
-- ----------------------------
DROP TABLE IF EXISTS `sys_group`;
CREATE TABLE `sys_group`  (
  `id` int NOT NULL,
  `group_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `avatar` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `created` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `year` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_group
-- ----------------------------

-- ----------------------------
-- Table structure for sys_knowledge
-- ----------------------------
DROP TABLE IF EXISTS `sys_knowledge`;
CREATE TABLE `sys_knowledge`  (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `knowledge_name` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `knowledge_name`(`knowledge_name`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 608 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_knowledge
-- ----------------------------
INSERT INTO `sys_knowledge` VALUES (601, 'c#');
INSERT INTO `sys_knowledge` VALUES (403, 'G代码');
INSERT INTO `sys_knowledge` VALUES (501, 'halcon');
INSERT INTO `sys_knowledge` VALUES (502, 'IP');
INSERT INTO `sys_knowledge` VALUES (302, 'OPC');
INSERT INTO `sys_knowledge` VALUES (305, 'PLC');
INSERT INTO `sys_knowledge` VALUES (101, 'SW/UG软件使用');
INSERT INTO `sys_knowledge` VALUES (602, 'winform');
INSERT INTO `sys_knowledge` VALUES (304, '信号量');
INSERT INTO `sys_knowledge` VALUES (103, '加工工艺');
INSERT INTO `sys_knowledge` VALUES (604, '回调');
INSERT INTO `sys_knowledge` VALUES (401, '回零模式');
INSERT INTO `sys_knowledge` VALUES (511, '图像分割');
INSERT INTO `sys_knowledge` VALUES (504, '图像格式和存储');
INSERT INTO `sys_knowledge` VALUES (509, '平滑');
INSERT INTO `sys_knowledge` VALUES (204, '开环和闭环');
INSERT INTO `sys_knowledge` VALUES (606, '异常处理');
INSERT INTO `sys_knowledge` VALUES (510, '形态学');
INSERT INTO `sys_knowledge` VALUES (402, '插补原理');
INSERT INTO `sys_knowledge` VALUES (608, '数据库');
INSERT INTO `sys_knowledge` VALUES (607, '日志');
INSERT INTO `sys_knowledge` VALUES (102, '机械设计');
INSERT INTO `sys_knowledge` VALUES (306, '梯形图');
INSERT INTO `sys_knowledge` VALUES (201, '生产装配');
INSERT INTO `sys_knowledge` VALUES (202, '电器元件');
INSERT INTO `sys_knowledge` VALUES (503, '畸变');
INSERT INTO `sys_knowledge` VALUES (512, '目标识别');
INSERT INTO `sys_knowledge` VALUES (505, '直方图');
INSERT INTO `sys_knowledge` VALUES (506, '空间滤波');
INSERT INTO `sys_knowledge` VALUES (603, '线程');
INSERT INTO `sys_knowledge` VALUES (203, '编码盘');
INSERT INTO `sys_knowledge` VALUES (605, '设计模式');
INSERT INTO `sys_knowledge` VALUES (303, '运动副');
INSERT INTO `sys_knowledge` VALUES (205, '运动模式');
INSERT INTO `sys_knowledge` VALUES (301, '通讯协议');
INSERT INTO `sys_knowledge` VALUES (508, '锐化');
INSERT INTO `sys_knowledge` VALUES (507, '频域滤波');

-- ----------------------------
-- Table structure for sys_subgroup
-- ----------------------------
DROP TABLE IF EXISTS `sys_subgroup`;
CREATE TABLE `sys_subgroup`  (
  `id` int NOT NULL,
  `subgroup_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `created` datetime NULL DEFAULT NULL,
  `avatar` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `year` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_subgroup
-- ----------------------------

-- ----------------------------
-- Table structure for sys_task
-- ----------------------------
DROP TABLE IF EXISTS `sys_task`;
CREATE TABLE `sys_task`  (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `task_name` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `task_name`(`task_name`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 23 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_task
-- ----------------------------
INSERT INTO `sys_task` VALUES (9, '回零');
INSERT INTO `sys_task` VALUES (16, '图像处理');
INSERT INTO `sys_task` VALUES (15, '图像采集');
INSERT INTO `sys_task` VALUES (11, '圆弧插补');
INSERT INTO `sys_task` VALUES (22, '异常处理与日志');
INSERT INTO `sys_task` VALUES (23, '数据库开发');
INSERT INTO `sys_task` VALUES (14, '标定');
INSERT INTO `sys_task` VALUES (12, '样条插补');
INSERT INTO `sys_task` VALUES (6, '电机参数设置');
INSERT INTO `sys_task` VALUES (5, '电机在线指令');
INSERT INTO `sys_task` VALUES (4, '电机整定');
INSERT INTO `sys_task` VALUES (3, '电路接线');
INSERT INTO `sys_task` VALUES (19, '界面设计与实现');
INSERT INTO `sys_task` VALUES (10, '直线插补');
INSERT INTO `sys_task` VALUES (21, '相机二次开发');
INSERT INTO `sys_task` VALUES (1, '绘制零件图');
INSERT INTO `sys_task` VALUES (8, '编写PLC程序');
INSERT INTO `sys_task` VALUES (2, '装配图');
INSERT INTO `sys_task` VALUES (17, '识别/定位/测量');
INSERT INTO `sys_task` VALUES (20, '运动控制二次开发');
INSERT INTO `sys_task` VALUES (13, '连接相机');
INSERT INTO `sys_task` VALUES (7, '配置运动副和信号量');
INSERT INTO `sys_task` VALUES (18, '需求分析');

-- ----------------------------
-- Table structure for sys_user
-- ----------------------------
DROP TABLE IF EXISTS `sys_user`;
CREATE TABLE `sys_user`  (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `userid` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL COMMENT '学号',
  `username` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `password` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `avatar` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `email` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `city` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `role` int NOT NULL COMMENT '类型 0学生 1老师 2超级管理员',
  `year` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `created` datetime NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `userid`(`userid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 3 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_user
-- ----------------------------
INSERT INTO `sys_user` VALUES (1, '111', 'admin', '123456', NULL, NULL, NULL, 2, '2023', '2023-12-01 00:00:00');
INSERT INTO `sys_user` VALUES (2, '2016124063', '张三', '123456', NULL, NULL, NULL, 0, '2023', '2023-12-01 00:00:00');

SET FOREIGN_KEY_CHECKS = 1;

/*
 Navicat Premium Data Transfer

 Source Server         : user
 Source Server Type    : SQLite
 Source Server Version : 3021000
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3021000
 File Encoding         : 65001

 Date: 07/12/2023 17:32:59
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS "user";
CREATE TABLE "user" (
  "id" integer PRIMARY KEY AUTOINCREMENT,
  "username" ntext NOT NULL,
  "password" ntext NOT NULL,
  "realname" TEXT,
  "studentnum" TEXT,
  "college" TEXT,
  "major" TEXT,
  "loginTime" TEXT,
  UNIQUE ("username" ASC)
);

-- ----------------------------
-- Auto increment value for user
-- ----------------------------
UPDATE "sqlite_sequence" SET seq = 2 WHERE name = 'user';

PRAGMA foreign_keys = true;

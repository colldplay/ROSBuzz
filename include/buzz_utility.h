#pragma once
#include <stdio.h>
#include "buzz_utility.h"
#include "buzzuav_closures.h"
#include "buzz_update.h"
#include <buzz/buzzdebug.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <stdint.h>
#include <map>

using namespace std;
namespace buzz_utility{

struct pos_struct
{
  double x,y,z;
  pos_struct(double x,double y,double z):x(x),y(y),z(z){};
  pos_struct(){}
};
typedef struct pos_struct Pos_struct;
struct rb_struct
{
  double r,b,la,lo;
  rb_struct(double la, double lo, double r,double b):la(la),lo(lo),r(r),b(b){};
  rb_struct(){}
};
typedef struct rb_struct RB_struct;

struct neiStatus
{
  uint gps_strenght = 0;
  uint batt_lvl = 0;
  uint xbee = 0;
  uint flight_status = 0;
}; typedef struct neiStatus neighbors_status ;


uint16_t* u64_cvt_u16(uint64_t u64);

int buzz_listen(const char* type,
                       int msg_size);

void add_user(int id, double latitude, double longitude, float altitude);
void update_users();
int make_table(buzzobj_t* t);
int buzzusers_add(int id, double latitude, double longitude, double altitude);
int buzzusers_reset();
	int compute_users_rb();
	int create_stig_tables();

void in_msg_append(uint64_t* payload);

uint64_t* obt_out_msg();

void update_sensors();

int buzz_script_set(const char* bo_filename,
                           const char* bdbg_filename, int robot_id);

int buzz_update_set(uint8_t* UP_BO_BUF, const char* bdbg_filename,size_t bcode_size);

int buzz_update_init_test(uint8_t* UP_BO_BUF, const char* bdbg_filename,size_t bcode_size);

void buzz_script_step();

void buzz_script_destroy();

int buzz_script_done();

int update_step_test();

int get_robotid();

buzzvm_t get_vm();

void set_robot_var(int ROBOTS);

int get_inmsg_size();
}

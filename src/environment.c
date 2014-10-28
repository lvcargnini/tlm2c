/*
 * environment.c
 *
 * Copyright (C) 2014, GreenSocs Ltd.
 *
 * Developped by Konrad Frederic <fred.konrad@greensocs.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses>.
 *
 * Linking GreenSocs code, statically or dynamically with other modules
 * is making a combined work based on GreenSocs code. Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * In addition, as a special exception, the copyright holders, GreenSocs
 * Ltd, give you permission to combine GreenSocs code with free software
 * programs or libraries that are released under the GNU LGPL, under the
 * OSCI license, under the OCP TLM Kit Research License Agreement or
 * under the OVP evaluation license.You may copy and distribute such a
 * system following the terms of the GNU GPL and the licenses of the
 * other code concerned.
 *
 * Note that people who make modified versions of GreenSocs code are not
 * obligated to grant this special exception for their modified versions;
 * it is their choice whether to do so. The GNU General Public License
 * gives permission to release a modified version without this exception;
 * this exception also makes it possible to release a modified version
 * which carries forward this exception.
 *
 */

#include "tlm2c/environment.h"

#include <string.h>

uint64_t default_get_time_ns(void *handler);
void default_request_stop(void *handler);
void default_request_notify(void *handler, uint64_t time_ns);
uint64_t default_get_uint_param(void *handler, const char *name);
int64_t default_get_int_param(void *handler, const char *name);
void default_get_string_param(void *handler, const char *name, char **param);
void default_get_param_list(void *handler, char **list[], size_t *size);

Environment global_env =
{
  .get_time_ns = default_get_time_ns,
  .request_stop = default_request_stop,
  .request_notify = default_request_notify,
  .get_uint_param = default_get_uint_param,
  .get_int_param = default_get_int_param,
  .get_string_param = default_get_string_param,
  .get_param_list = default_get_param_list,
  .handler = NULL
};

void tlm2c_set_environment(Environment *env)
{
  memcpy(&global_env, env, sizeof(Environment));
}

Environment *get_env(void)
{
  return &global_env;
}

uint64_t default_get_time_ns(void *handler)
{
  return 0;
}

void default_request_stop(void *handler)
{
  abort();
}

void default_request_notify(void *handler, uint64_t time_ns)
{

}

uint64_t default_get_uint_param(void *handler, const char *name)
{
  return 0;
}

int64_t default_get_int_param(void *handler, const char *name)
{
  return 0;
}

void default_get_string_param(void *handler, const char *name, char **param)
{
  *param = NULL;
}

void default_get_param_list(void *handler, char **list[], size_t *size)
{
  *list = NULL;
  *size = 0;
}

uint64_t env_get_time_ns(Environment *env)
{
  return env->get_time_ns(env->handler);
}

void env_request_notify(Environment *env, uint64_t time_ns)
{
  env->request_notify(env->handler, time_ns);
}

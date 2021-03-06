/*
 * model.h
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

#ifndef MODEL_H
#define MODEL_H

typedef struct Model Model;

#include "method.h"
#include "socket.h"

typedef void (*eoe_cb)(Model *model);
typedef void (*sos_cb)(Model *model);

struct Model
{
  /* private */
  char *name;
  eoe_cb end_of_elaboration;
  sos_cb start_of_simulation;
  Method *methods;
  Socket *sockets;
  Model *next;
};

void model_init(Model *model, const char *name);
const char *tlm2c_model_get_name(Model *model);
void model_add_method(Model *model, Method *method);
void model_register_end_of_elaboration(Model *model, eoe_cb cb);
void model_register_start_of_simulation(Model *model, sos_cb cb);
void model_add_socket(Model *model, Socket *socket);
void model_destroy(Model *model);
void model_end_of_elaboration(Model *model);
void model_start_of_simulation(Model *model);
void model_notify(Model *model);
Model *get_models(void);

#endif /* !MODEL_H */

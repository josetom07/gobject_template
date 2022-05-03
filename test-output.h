/*
 * test-output.h
 * This file is part of Test-Project
 *
 * Copyright (C) 2022 - Jose-Pablo Tamayo
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef TEST_OUTPUT_H_INCLUDED
#define TEST_OUTPUT_H_INCLUDED

#include <stdio.h>

G_BEGIN_DECLS

#define TEST_TYPE_EXAMPLE_INST\
  (test_example_inst_get_type ())
#define TEST_EXAMPLE_INST(obj)\
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), TEST_TYPE_EXAMPLE_INST, TestExampleInst))
#define TEST_EXAMPLE_IS_INST(obj)\
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TEST_TYPE_EXAMPLE_INST))
#define TEST_EXAMPLE_INST_CLASS(klass)\
  (G_TYPE_CHECK_CLASS_CAST ((klass), TEST_TYPE_EXAMPLE_INST, TestExampleInstClass))
#define TEST_EXAMPLE_INST_IS_CLASS(klass)\
  (G_TYPE_CHECK_CLASS_TYPE ((klass), TEST_TYPE_EXAMPLE_INST))
#define TEST_EXAMPLE_INST_GET_CLASS(obj)\
  (G_TYPE_INSTANCE_GET_CLASS ((obj), TEST_TYPE_EXAMPLE_INST, TestExampleInstClass))

typedef struct _TestExampleInst TestExampleInst;
typedef struct _TestExampleInstClass TestExampleInstClass;
typedef struct _TestExampleInstPrivate TestExampleInstPrivate;

struct _TestExampleInst
{
  TestExampleParent parent;

  /*< private > */
  TestExampleInstPrivate* priv;
};

struct _TestExampleInstClass
{
  TestExampleParentClass parent_class;

  gpointer padding[8];
};

/* Public Method definitions. */
GType test_example_inst_get_type (void) ;

TestExampleInst * test_example_inst_new(void);

G_END_DECLS

#endif // TEST_OUTPUT_H_INCLUDED

/*
 * test-output.c
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "test-output.h"



#define TEST_EXAMPLE_INST_GET_PRIVATE(obj)\
 (G_TYPE_INSTANCE_GET_PRIVATE ((obj),\
 TEST_TYPE_EXAMPLE_INST,\
 TestExampleInstPrivate))

/* Define Properties */
enum
{
  PROP_0,

  PROP_XMPL_PROP,

  N_PROPERTIES
};
#define test_example_inst_parent_class parent_class
struct _TestExampleInstPrivate
{
  gdouble  xmpl_prop;
};

G_DEFINE_TYPE_WITH_PRIVATE (TestExampleInst, test_example_inst,
                            TEST_TYPE_EXAMPLE_PARENT);


static void
test_example_inst_init (TestExampleInst* self)
{

  self->priv = test_example_inst_get_instance_private (self);


  /* predefined values */

  self->priv->xmpl_prop = 1000.0;



}

static void
test_example_inst_set_property (GObject*      object,
  guint         property_id,
  const GValue* value,
  GParamSpec*   pspec)
{
  TestExampleInst* self = TEST_EXAMPLE_INST (object);

  TestExampleInstPrivate * priv = self->priv;


  switch (property_id)
  {
  case PROP_XMPL_PROP:
    priv->xmpl_prop = g_value_get_double(value);
    break;

  default:
    /* unknown property */
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }

}

static void
test_example_inst_get_property (GObject*    object,
  guint       property_id,
  GValue*     value,
  GParamSpec* pspec)
{
  TestExampleInst* self = TEST_EXAMPLE_INST (object);

  TestExampleInstPrivate * priv = self->priv;


  switch (property_id)
  {
  case PROP_XMPL_PROP:
    g_value_set_double (value, priv->xmpl_prop);
    break;

  default:
    /* unknown property */
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}

static void
test_example_inst_dispose (GObject* object)
{
//  TestExampleInst* self = TEST_EXAMPLE_INST (object);

  G_OBJECT_CLASS (parent_class)->dispose (object);
}

static void
test_example_inst_finalize (GObject* object)
{
//  TestExampleInst* self = TEST_EXAMPLE_INST (object);

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
test_example_inst_class_init (TestExampleInstClass* klass)
{
  GObjectClass* object_class = G_OBJECT_CLASS (klass);
//  TestExampleInstClass *test_example_inst_class = TEST_EXAMPLE_INST_CLASS (klass);




  object_class->dispose = test_example_inst_dispose;
  object_class->finalize = test_example_inst_finalize;
object_class->set_property = test_example_inst_set_property;
  object_class->get_property = test_example_inst_get_property;

/* Properties */

  g_object_class_install_property (object_class, 
    PROP_XMPL_PROP,
    g_para_spec_double ("xmpl_prop",
      "Example Property",
      "Holds an example property",
      0.0,
      G_MAXDOUBLE,
      1000.0,
      G_PARAM_READWRITE);

}

TestExampleInst * test_example_inst_new(void)
{
  /* FIXME! */
}
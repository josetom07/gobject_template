#!/usr/bin/env python3

from jinja2 import Template
import re
import datetime

class property ():
  name = ''
  nick = ''
  blurb = ''
  type = ''
  max = ''
  min = ''
  default = ''
  flags = ''
  subtype = ''

  def __init__(self, *initial_data, **kwargs):
    for dictionary in initial_data:
      for key, value in dictionary.items():
        setattr(self, key, value)

    for key in kwargs:
      setattr(self, key, kwargs[key])

input_files = {
  'my_obj.c.j2' : 'test-output.c',
  'my_obj.h.j2' : 'test-output.h',
}

configs = {
  'author' :'Jose-Pablo Tamayo',
  'license' : ''' * This program is free software; you can redistribute it and/or modify
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
 * Boston, MA 02111-1307, USA.''',
  'year' : datetime.date.today().year,
  'project_name' : 'Test-Project',
  'with_private' : True,
  'classic_types' : True,
  'public_private' : True,

  # Now begins the "more specific" part
  'header_includes' : [
      'stdio.h',
  ],
  'lib_source_includes' : [
  ],
  'source_includes' : [
  ],
  'type_name': 'TEST_EXAMPLE_INST',
  'parent_type': 'TEST_EXAMPLE_PARENT',
  'signals' : [
  ],
  'methods' : [
     'TestExampleInst * test_example_inst_new(void);'
  ],
  'properties' : [
   property(name='xmpl_prop', nick='Example Property',
            blurb='Holds an example property',
            type='double',min='0.0',max='G_MAXDOUBLE',default='1000.0',
            flags='G_PARAM_READWRITE')
  ]
}

for in_file_name, out_file_name in input_files.items():

  with open(in_file_name, "r+") as file:
      header_name = re.sub('\..$', '.h', out_file_name)

      # Reading form a file
      template = Template(file.read())

      with open(out_file_name, "w") as out_file:

        configs['file_name'] = out_file_name
        configs['header_name'] = header_name
        out_file.write(template.render(configs))

  file.close()
  out_file.close()


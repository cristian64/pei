interfacesGlade = "<?xml version=\"1.0\"?><glade-interface>  <!-- interface-requires gtk+ 2.16 -->  <!-- interface-naming-policy project-wide -->  <widget class=\"GtkWindow\" id=\"MainWindow\">    <property name=\"title\" translatable=\"yes\">Vista Gtkmm</property>    <property name=\"default_width\">900</property>    <property name=\"default_height\">700</property>    <property name=\"icon_name\">applications-other</property>    <child>      <widget class=\"GtkVBox\" id=\"vbox1\">        <property name=\"visible\">True</property>        <child>          <widget class=\"GtkMenuBar\" id=\"menubar\">            <property name=\"visible\">True</property>            <child>              <widget class=\"GtkMenuItem\" id=\"menuitemArchivo\">                <property name=\"visible\">True</property>                <property name=\"label\" translatable=\"yes\">_Archivo</property>                <property name=\"use_underline\">True</property>                <child>                  <widget class=\"GtkMenu\" id=\"menuArchivo\">                    <property name=\"visible\">True</property>                    <child>                      <widget class=\"GtkImageMenuItem\" id=\"imagemenuitemNuevo\">                        <property name=\"label\">gtk-new</property>                        <property name=\"visible\">True</property>                        <property name=\"use_underline\">True</property>                        <property name=\"use_stock\">True</property>                      </widget>                    </child>                    <child>                      <widget class=\"GtkImageMenuItem\" id=\"imagemenuitemAbrir\">                        <property name=\"label\">gtk-open</property>                        <property name=\"visible\">True</property>                        <property name=\"use_underline\">True</property>                        <property name=\"use_stock\">True</property>                      </widget>                    </child>                    <child>                      <widget class=\"GtkImageMenuItem\" id=\"imagemenuitemGuardar\">                        <property name=\"label\">gtk-save</property>                        <property name=\"visible\">True</property>                        <property name=\"use_underline\">True</property>                        <property name=\"use_stock\">True</property>                      </widget>                    </child>                    <child>                      <widget class=\"GtkImageMenuItem\" id=\"imagemenuitemGuardarComo\">                        <property name=\"label\">gtk-save-as</property>                        <property name=\"visible\">True</property>                        <property name=\"use_underline\">True</property>                        <property name=\"use_stock\">True</property>                      </widget>                    </child>                    <child>                      <widget class=\"GtkSeparatorMenuItem\" id=\"separatormenuitem\">                        <property name=\"visible\">True</property>                      </widget>                    </child>                    <child>                      <widget class=\"GtkImageMenuItem\" id=\"imagemenuitemSalir\">                        <property name=\"label\">gtk-quit</property>                        <property name=\"visible\">True</property>                        <property name=\"use_underline\">True</property>                        <property name=\"use_stock\">True</property>                      </widget>                    </child>                  </widget>                </child>              </widget>            </child>            <child>              <widget class=\"GtkMenuItem\" id=\"menuitemAyuda\">                <property name=\"visible\">True</property>                <property name=\"label\" translatable=\"yes\">Ay_uda</property>                <property name=\"use_underline\">True</property>                <child>                  <widget class=\"GtkMenu\" id=\"menuAyuda\">                    <property name=\"visible\">True</property>                    <child>                      <widget class=\"GtkImageMenuItem\" id=\"imagemenuitemAcercaDe\">                        <property name=\"label\">gtk-about</property>                        <property name=\"visible\">True</property>                        <property name=\"use_underline\">True</property>                        <property name=\"use_stock\">True</property>                      </widget>                    </child>                  </widget>                </child>              </widget>            </child>          </widget>          <packing>            <property name=\"expand\">False</property>            <property name=\"position\">0</property>          </packing>        </child>        <child>          <widget class=\"GtkToolbar\" id=\"toolbar\">            <property name=\"visible\">True</property>            <property name=\"toolbar_style\">both-horiz</property>            <child>              <widget class=\"GtkToolButton\" id=\"toolbuttonNuevo\">                <property name=\"visible\">True</property>                <property name=\"label\" translatable=\"yes\">Nuevo documento en blanco</property>                <property name=\"use_underline\">True</property>                <property name=\"icon_name\">document-new</property>              </widget>              <packing>                <property name=\"expand\">False</property>                <property name=\"homogeneous\">True</property>              </packing>            </child>            <child>              <widget class=\"GtkToolButton\" id=\"toolbuttonAbrir\">                <property name=\"visible\">True</property>                <property name=\"label\" translatable=\"yes\">Abrir asignaturas</property>                <property name=\"use_underline\">True</property>                <property name=\"icon_name\">document-open</property>              </widget>              <packing>                <property name=\"expand\">False</property>                <property name=\"homogeneous\">True</property>              </packing>            </child>            <child>              <widget class=\"GtkToolButton\" id=\"toolbuttonGuardar\">                <property name=\"visible\">True</property>                <property name=\"label\" translatable=\"yes\">Guardar asignaturas</property>                <property name=\"use_underline\">True</property>                <property name=\"icon_name\">document-save</property>              </widget>              <packing>                <property name=\"expand\">False</property>                <property name=\"homogeneous\">True</property>              </packing>            </child>            <child>              <widget class=\"GtkToolButton\" id=\"toolbuttonGuardarComo\">                <property name=\"visible\">True</property>                <property name=\"label\" translatable=\"yes\">Guardar asignaturas como</property>                <property name=\"use_underline\">True</property>                <property name=\"icon_name\">document-save-as</property>              </widget>              <packing>                <property name=\"expand\">False</property>                <property name=\"homogeneous\">True</property>              </packing>            </child>            <child>              <widget class=\"GtkSeparatorToolItem\" id=\"toolbuttonSeparador\">                <property name=\"visible\">True</property>              </widget>              <packing>                <property name=\"expand\">False</property>                <property name=\"homogeneous\">True</property>              </packing>            </child>            <child>              <widget class=\"GtkToolButton\" id=\"toolbuttonAnadir\">                <property name=\"visible\">True</property>                <property name=\"is_important\">True</property>                <property name=\"label\" translatable=\"yes\">A&#xF1;adir asignatura</property>                <property name=\"use_underline\">True</property>                <property name=\"icon_name\">add</property>              </widget>              <packing>                <property name=\"expand\">False</property>                <property name=\"homogeneous\">True</property>              </packing>            </child>            <child>              <widget class=\"GtkToolButton\" id=\"toolbuttonQuitar\">                <property name=\"visible\">True</property>                <property name=\"is_important\">True</property>                <property name=\"label\" translatable=\"yes\">Quitar asignatura</property>                <property name=\"use_underline\">True</property>                <property name=\"icon_name\">remove</property>              </widget>              <packing>                <property name=\"expand\">False</property>                <property name=\"homogeneous\">True</property>              </packing>            </child>          </widget>          <packing>            <property name=\"expand\">False</property>            <property name=\"position\">1</property>          </packing>        </child>        <child>          <widget class=\"GtkHPaned\" id=\"hpaned\">            <property name=\"visible\">True</property>            <property name=\"can_focus\">True</property>            <property name=\"position\">200</property>            <property name=\"position_set\">True</property>            <child>              <widget class=\"GtkTreeView\" id=\"treeviewAsignaturas\">                <property name=\"visible\">True</property>                <property name=\"can_focus\">True</property>              </widget>              <packing>                <property name=\"resize\">False</property>                <property name=\"shrink\">True</property>              </packing>            </child>            <child>              <widget class=\"GtkNotebook\" id=\"notebookDetalles\">                <property name=\"visible\">True</property>                <property name=\"can_focus\">True</property>                <child>                  <widget class=\"GtkLabel\" id=\"label4\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Profesores</property>                  </widget>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"labelProfesores\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Profesores</property>                  </widget>                  <packing>                    <property name=\"tab_fill\">False</property>                    <property name=\"type\">tab</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"label24\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Compa&#xF1;eros</property>                  </widget>                  <packing>                    <property name=\"position\">1</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"labelCompaneros\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Compa&#xF1;eros</property>                  </widget>                  <packing>                    <property name=\"position\">1</property>                    <property name=\"tab_fill\">False</property>                    <property name=\"type\">tab</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"label14\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Sesiones</property>                  </widget>                  <packing>                    <property name=\"position\">2</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"labelSesiones\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Sesiones</property>                  </widget>                  <packing>                    <property name=\"position\">2</property>                    <property name=\"tab_fill\">False</property>                    <property name=\"type\">tab</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"label8\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Citas</property>                  </widget>                  <packing>                    <property name=\"position\">3</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"labelNotas\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Notas</property>                  </widget>                  <packing>                    <property name=\"position\">2</property>                    <property name=\"tab_fill\">False</property>                    <property name=\"type\">tab</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"label5\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Notas</property>                  </widget>                  <packing>                    <property name=\"position\">4</property>                  </packing>                </child>                <child>                  <widget class=\"GtkLabel\" id=\"labelCitas\">                    <property name=\"visible\">True</property>                    <property name=\"label\" translatable=\"yes\">Citas</property>                  </widget>                  <packing>                    <property name=\"position\">2</property>                    <property name=\"tab_fill\">False</property>                    <property name=\"type\">tab</property>                  </packing>                </child>              </widget>              <packing>                <property name=\"resize\">True</property>                <property name=\"shrink\">True</property>              </packing>            </child>          </widget>          <packing>            <property name=\"position\">2</property>          </packing>        </child>        <child>          <widget class=\"GtkStatusbar\" id=\"statusbar\">            <property name=\"visible\">True</property>            <property name=\"spacing\">2</property>          </widget>          <packing>            <property name=\"expand\">False</property>            <property name=\"position\">3</property>          </packing>        </child>      </widget>    </child>  </widget></glade-interface>";
//
// Created by Administrator on 2019/5/14.
//
#include "il2cpp-api.h"
#define CallIl2CppFun1(funname, par) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )(par);

#define CallIl2CppFun0(funname) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )();

#define CallIl2CppFun2(funname, p1, p2) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )(p1, p2);

#define CallIl2CppFun3(funname, p1, p2, p3) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )(p1, p2, p3);

#define CallIl2CppFun4(funname, p1, p2, p3, p4) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )(p1, p2, p3, p4);

#define CallIl2CppFun5(funname, p1, p2, p3, p4, p5) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )(p1, p2, p3, p4, p5);

#define CallIl2CppFun6(funname, p1, p2, p3, p4, p5, p6) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )(p1, p2, p3, p4, p5, p6);

#define CallIl2CppFun7(funname, p1, p2, p3, p4, p5, p6, p7) \
extern void* g_##funname;\
return ((p_##funname)g_##funname )(p1, p2, p3, p4, p5, p6, p7);

void il2cpp_init(const char* domain_name)
{
    CallIl2CppFun1(il2cpp_init, domain_name);
}

void il2cpp_init_utf16(const Il2CppChar* domain_name)
{
    CallIl2CppFun1(il2cpp_init_utf16, domain_name);
}

void il2cpp_shutdown()
{
    CallIl2CppFun0(il2cpp_shutdown);
}

void il2cpp_set_config_dir(const char *config_path)
{
    CallIl2CppFun1(il2cpp_set_config_dir, config_path);
}

void il2cpp_set_data_dir(const char *data_path)
{
    CallIl2CppFun1(il2cpp_set_data_dir, data_path);
}

void il2cpp_set_temp_dir(const char *temp_dir)
{
    CallIl2CppFun1(il2cpp_set_temp_dir, temp_dir);
}

void il2cpp_set_commandline_arguments(int argc, const char* const argv[], const char* basedir)
{
    CallIl2CppFun3(il2cpp_set_commandline_arguments, argc, argv, basedir);
}

void il2cpp_set_commandline_arguments_utf16(int argc, const Il2CppChar* const argv[], const char* basedir)
{
    CallIl2CppFun3(il2cpp_set_commandline_arguments_utf16, argc, argv, basedir);
}

void il2cpp_set_config_utf16(const Il2CppChar* executablePath)
{
    CallIl2CppFun1(il2cpp_set_config_utf16, executablePath);
}

void il2cpp_set_config(const char* executablePath)
{
    CallIl2CppFun1(il2cpp_set_config, executablePath);
}

void il2cpp_set_memory_callbacks(Il2CppMemoryCallbacks* callbacks)
{
    CallIl2CppFun1(il2cpp_set_memory_callbacks, callbacks);
}

const Il2CppImage* il2cpp_get_corlib()
{
    CallIl2CppFun0(il2cpp_get_corlib);
}

void il2cpp_add_internal_call(const char* name, Il2CppMethodPointer method)
{
    CallIl2CppFun2(il2cpp_add_internal_call, name, method);
}

Il2CppMethodPointer il2cpp_resolve_icall(const char* name)
{
    CallIl2CppFun1(il2cpp_resolve_icall, name);
}

void* il2cpp_alloc(size_t size)
{
    CallIl2CppFun1(il2cpp_alloc, size);
}

void il2cpp_free(void* ptr)
{
    CallIl2CppFun1(il2cpp_free, ptr);
}

// array

Il2CppClass *il2cpp_array_class_get(Il2CppClass *element_class, uint32_t rank)
{
    CallIl2CppFun2(il2cpp_array_class_get, element_class, rank);
}

uint32_t il2cpp_array_length(Il2CppArray* array)
{
    CallIl2CppFun1(il2cpp_array_length, array);
}

uint32_t il2cpp_array_get_byte_length(Il2CppArray *array)
{
    CallIl2CppFun1(il2cpp_array_get_byte_length, array);
}

Il2CppArray* il2cpp_array_new(Il2CppClass *elementTypeInfo, il2cpp_array_size_t length)
{
    CallIl2CppFun2(il2cpp_array_new, elementTypeInfo, length);
}

Il2CppArray* il2cpp_array_new_specific(Il2CppClass *arrayTypeInfo, il2cpp_array_size_t length)
{
    CallIl2CppFun2(il2cpp_array_new_specific, arrayTypeInfo, length);
}

Il2CppArray* il2cpp_array_new_full(Il2CppClass *array_class, il2cpp_array_size_t *lengths, il2cpp_array_size_t *lower_bounds)
{
    CallIl2CppFun3(il2cpp_array_new_full, array_class, lengths, lower_bounds);
}

Il2CppClass* il2cpp_bounded_array_class_get(Il2CppClass *element_class, uint32_t rank, bool bounded)
{
    CallIl2CppFun3(il2cpp_bounded_array_class_get, element_class, rank, bounded);
}

int il2cpp_array_element_size(const Il2CppClass* klass)
{
    CallIl2CppFun1(il2cpp_array_element_size, klass);
}

// assembly
const Il2CppImage* il2cpp_assembly_get_image(const Il2CppAssembly *assembly)
{
    CallIl2CppFun1(il2cpp_assembly_get_image, assembly);
}

// class

const Il2CppType* il2cpp_class_enum_basetype(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_enum_basetype, klass);
}

Il2CppClass* il2cpp_class_from_system_type(Il2CppReflectionType *type)
{
    CallIl2CppFun1(il2cpp_class_from_system_type, type);
}

bool il2cpp_class_is_generic(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_is_generic, klass);
}

bool il2cpp_class_is_inflated(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_is_inflated, klass);
}

bool il2cpp_class_is_assignable_from(Il2CppClass *klass, Il2CppClass *oklass)
{
    CallIl2CppFun2(il2cpp_class_is_assignable_from, klass, oklass);
}

bool il2cpp_class_is_subclass_of(Il2CppClass *klass, Il2CppClass *klassc, bool check_interfaces)
{
    CallIl2CppFun3(il2cpp_class_is_subclass_of, klass, klassc, check_interfaces);
}

bool il2cpp_class_has_parent(Il2CppClass *klass, Il2CppClass *klassc)
{
    CallIl2CppFun2(il2cpp_class_has_parent, klass, klassc);
}

Il2CppClass* il2cpp_class_from_il2cpp_type(const Il2CppType* type)
{
    CallIl2CppFun1(il2cpp_class_from_il2cpp_type, type);
}

Il2CppClass* il2cpp_class_from_name(const Il2CppImage* image, const char* namespaze, const char *name)
{
    CallIl2CppFun3(il2cpp_class_from_name, image, namespaze, name);
}

Il2CppClass* il2cpp_class_get_element_class(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_element_class, klass);
}

const EventInfo* il2cpp_class_get_events(Il2CppClass *klass, void* *iter)
{
    CallIl2CppFun2(il2cpp_class_get_events, klass, iter);
}

FieldInfo* il2cpp_class_get_fields(Il2CppClass *klass, void* *iter)
{
    CallIl2CppFun2(il2cpp_class_get_fields, klass, iter);
}

Il2CppClass* il2cpp_class_get_nested_types(Il2CppClass *klass, void* *iter)
{
    CallIl2CppFun2(il2cpp_class_get_nested_types, klass, iter);
}

Il2CppClass* il2cpp_class_get_interfaces(Il2CppClass *klass, void* *iter)
{
    CallIl2CppFun2(il2cpp_class_get_interfaces, klass, iter);
}

const PropertyInfo* il2cpp_class_get_properties(Il2CppClass *klass, void* *iter)
{
    CallIl2CppFun2(il2cpp_class_get_properties, klass, iter);
}

const PropertyInfo* il2cpp_class_get_property_from_name(Il2CppClass *klass, const char *name)
{
    CallIl2CppFun2(il2cpp_class_get_property_from_name, klass, name);
}

FieldInfo* il2cpp_class_get_field_from_name(Il2CppClass* klass, const char *name)
{
    CallIl2CppFun2(il2cpp_class_get_field_from_name, klass, name);
}

const MethodInfo* il2cpp_class_get_methods(Il2CppClass *klass, void* *iter)
{
    CallIl2CppFun2(il2cpp_class_get_methods, klass, iter);
}

const MethodInfo* il2cpp_class_get_method_from_name(Il2CppClass *klass, const char* name, int argsCount)
{
    CallIl2CppFun3(il2cpp_class_get_method_from_name, klass, name, argsCount);
}

const char* il2cpp_class_get_name(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_name, klass);
}

const char* il2cpp_class_get_namespace(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_namespace, klass);
}

Il2CppClass* il2cpp_class_get_parent(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_parent, klass);
}

Il2CppClass* il2cpp_class_get_declaring_type(Il2CppClass* klass)
{
    CallIl2CppFun1(il2cpp_class_get_declaring_type, klass);
}

int32_t il2cpp_class_instance_size(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_instance_size, klass);
}

size_t il2cpp_class_num_fields(const Il2CppClass* klass)
{
    CallIl2CppFun1(il2cpp_class_num_fields, klass);
}

bool il2cpp_class_is_valuetype(const Il2CppClass* klass)
{
    CallIl2CppFun1(il2cpp_class_is_valuetype, klass);
}

bool il2cpp_class_is_blittable(const Il2CppClass* klass)
{
    CallIl2CppFun1(il2cpp_class_is_blittable, klass);
}

int32_t il2cpp_class_value_size(Il2CppClass *klass, uint32_t *align)
{
    CallIl2CppFun2(il2cpp_class_value_size, klass, align);
}

int il2cpp_class_get_flags(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_flags, klass);
}

bool il2cpp_class_is_abstract(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_is_abstract, klass);
}

bool il2cpp_class_is_interface(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_is_interface, klass);
}

int il2cpp_class_array_element_size(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_array_element_size, klass);
}

Il2CppClass* il2cpp_class_from_type(const Il2CppType *type)
{
    CallIl2CppFun1(il2cpp_class_from_type, type);
}

const Il2CppType* il2cpp_class_get_type(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_type, klass);
}

uint32_t il2cpp_class_get_type_token(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_type_token, klass);
}

bool il2cpp_class_has_attribute(Il2CppClass *klass, Il2CppClass *attr_class)
{
    CallIl2CppFun2(il2cpp_class_has_attribute, klass, attr_class);
}

bool il2cpp_class_has_references(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_has_references, klass);
}

bool il2cpp_class_is_enum(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_is_enum, klass);
}

const Il2CppImage* il2cpp_class_get_image(Il2CppClass* klass)
{
    CallIl2CppFun1(il2cpp_class_get_image, klass);
}

const char *il2cpp_class_get_assemblyname(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_assemblyname, klass);
}

int il2cpp_class_get_rank(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_rank, klass);
}

// testing only
size_t il2cpp_class_get_bitmap_size(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_class_get_bitmap_size, klass);
}

void il2cpp_class_get_bitmap(Il2CppClass *klass, size_t* bitmap)
{
    CallIl2CppFun2(il2cpp_class_get_bitmap, klass, bitmap);
}

bool il2cpp_stats_dump_to_file(const char *path)
{
    CallIl2CppFun1(il2cpp_stats_dump_to_file, path);
}

uint64_t il2cpp_stats_get_value(Il2CppStat stat)
{
    CallIl2CppFun1(il2cpp_stats_get_value, stat);
}

// domain
Il2CppDomain* il2cpp_domain_get()
{
    CallIl2CppFun0(il2cpp_domain_get);
}

const Il2CppAssembly* il2cpp_domain_assembly_open(Il2CppDomain *domain, const char *name)
{
    CallIl2CppFun2(il2cpp_domain_assembly_open, domain, name);
}

const Il2CppAssembly** il2cpp_domain_get_assemblies(const Il2CppDomain* domain, size_t* size)
{
    CallIl2CppFun2(il2cpp_domain_get_assemblies, domain, size);
}

// exception

void il2cpp_raise_exception(Il2CppException* exc)
{
    CallIl2CppFun1(il2cpp_raise_exception, exc);
}

Il2CppException* il2cpp_exception_from_name_msg(const Il2CppImage* image, const char *name_space, const char *name, const char *msg)
{
    CallIl2CppFun4(il2cpp_exception_from_name_msg, image, name_space, name, msg);
}

Il2CppException* il2cpp_get_exception_argument_null(const char *arg)
{
    CallIl2CppFun1(il2cpp_get_exception_argument_null, arg);
}

void il2cpp_format_exception(const Il2CppException* ex, char* message, int message_size)
{
    CallIl2CppFun3(il2cpp_format_exception, ex, message, message_size);
}

void il2cpp_format_stack_trace(const Il2CppException* ex, char* output, int output_size)
{
    CallIl2CppFun3(il2cpp_format_stack_trace, ex, output, output_size);
}

void il2cpp_unhandled_exception(Il2CppException* exc)
{
    CallIl2CppFun1(il2cpp_unhandled_exception, exc);
}

// field

const char* il2cpp_field_get_name(FieldInfo *field)
{
    CallIl2CppFun1(il2cpp_field_get_name, field);
}

int il2cpp_field_get_flags(FieldInfo *field)
{
    CallIl2CppFun1(il2cpp_field_get_flags, field);
}

Il2CppClass* il2cpp_field_get_parent(FieldInfo *field)
{
    CallIl2CppFun1(il2cpp_field_get_parent, field);
}

size_t il2cpp_field_get_offset(FieldInfo *field)
{
    CallIl2CppFun1(il2cpp_field_get_offset, field);
}

const Il2CppType* il2cpp_field_get_type(FieldInfo *field)
{
    CallIl2CppFun1(il2cpp_field_get_type, field);
}

void il2cpp_field_get_value(Il2CppObject *obj, FieldInfo *field, void *value)
{
    CallIl2CppFun3(il2cpp_field_get_value, obj, field, value);
}

Il2CppObject* il2cpp_field_get_value_object(FieldInfo *field, Il2CppObject *obj)
{
    CallIl2CppFun2(il2cpp_field_get_value_object, field, obj);
}

bool il2cpp_field_has_attribute(FieldInfo *field, Il2CppClass *attr_class)
{
    CallIl2CppFun2(il2cpp_field_has_attribute, field, attr_class);
}

void il2cpp_field_set_value(Il2CppObject *obj, FieldInfo *field, void *value)
{
    CallIl2CppFun3(il2cpp_field_set_value, obj, field, value);
}

void il2cpp_field_set_value_object(Il2CppObject* objectInstance, FieldInfo* field, Il2CppObject* value)
{
    CallIl2CppFun3(il2cpp_field_set_value_object, objectInstance, field, value);
}

void il2cpp_field_static_get_value(FieldInfo *field, void *value)
{
    CallIl2CppFun2(il2cpp_field_static_get_value, field, value);
}

void il2cpp_field_static_set_value(FieldInfo *field, void *value)
{
    CallIl2CppFun2(il2cpp_field_static_set_value, field, value);
}

// gc
void il2cpp_gc_collect(int maxGenerations)
{
    CallIl2CppFun1(il2cpp_gc_collect, maxGenerations);
}

int32_t il2cpp_gc_collect_a_little()
{
    CallIl2CppFun0(il2cpp_gc_collect_a_little);
}

void il2cpp_gc_enable()
{
    CallIl2CppFun0(il2cpp_gc_enable);
}

void il2cpp_gc_disable()
{
    CallIl2CppFun0(il2cpp_gc_disable);
}

bool il2cpp_gc_is_disabled()
{
    CallIl2CppFun0(il2cpp_gc_is_disabled);
}

int64_t il2cpp_gc_get_used_size()
{
    CallIl2CppFun0(il2cpp_gc_get_used_size);
}

int64_t il2cpp_gc_get_heap_size()
{
    CallIl2CppFun0(il2cpp_gc_get_heap_size);
}

// gchandle

uint32_t il2cpp_gchandle_new(Il2CppObject *obj, bool pinned)
{
    CallIl2CppFun2(il2cpp_gchandle_new, obj, pinned);
}

uint32_t il2cpp_gchandle_new_weakref(Il2CppObject *obj, bool track_resurrection)
{
    CallIl2CppFun2(il2cpp_gchandle_new_weakref, obj, track_resurrection);
}

Il2CppObject* il2cpp_gchandle_get_target(uint32_t gchandle)
{
    CallIl2CppFun1(il2cpp_gchandle_get_target, gchandle);
}

void il2cpp_gc_wbarrier_set_field(Il2CppObject *obj, void **targetAddress, void *object)
{
    CallIl2CppFun3(il2cpp_gc_wbarrier_set_field, obj, targetAddress, object);
}

void il2cpp_gchandle_free(uint32_t gchandle)
{
    CallIl2CppFun1(il2cpp_gchandle_free, gchandle);
}

// liveness

void* il2cpp_unity_liveness_calculation_begin(Il2CppClass* filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped)
{
    CallIl2CppFun6(il2cpp_unity_liveness_calculation_begin, filter,
                   max_object_count,
                   callback,
                   userdata,
                   onWorldStarted,
                   onWorldStopped
    );
}

void il2cpp_unity_liveness_calculation_end(void* state)
{
    CallIl2CppFun1(il2cpp_unity_liveness_calculation_end, state);
}

void il2cpp_unity_liveness_calculation_from_root(Il2CppObject* root, void* state)
{
    CallIl2CppFun2(il2cpp_unity_liveness_calculation_from_root, root, state);
}

void il2cpp_unity_liveness_calculation_from_statics(void* state)
{
    CallIl2CppFun1(il2cpp_unity_liveness_calculation_from_statics, state);
}

// method

const Il2CppType* il2cpp_method_get_return_type(const MethodInfo* method)
{
    CallIl2CppFun1(il2cpp_method_get_return_type, method);
}

const MethodInfo* il2cpp_method_get_from_reflection(const Il2CppReflectionMethod *method)
{
    CallIl2CppFun1(il2cpp_method_get_from_reflection, method);
}

Il2CppReflectionMethod* il2cpp_method_get_object(const MethodInfo *method, Il2CppClass *refclass)
{
    CallIl2CppFun2(il2cpp_method_get_object, method, refclass);
}

const char* il2cpp_method_get_name(const MethodInfo *method)
{
    CallIl2CppFun1(il2cpp_method_get_name, method);
}

bool il2cpp_method_is_generic(const MethodInfo *method)
{
    CallIl2CppFun1(il2cpp_method_is_generic, method);
}

bool il2cpp_method_is_inflated(const MethodInfo *method)
{
    CallIl2CppFun1(il2cpp_method_is_inflated, method);
}

bool il2cpp_method_is_instance(const MethodInfo *method)
{
    CallIl2CppFun1(il2cpp_method_is_instance, method);
}

uint32_t il2cpp_method_get_param_count(const MethodInfo *method)
{
    CallIl2CppFun1(il2cpp_method_get_param_count, method);
}

const Il2CppType* il2cpp_method_get_param(const MethodInfo *method, uint32_t index)
{
    CallIl2CppFun2(il2cpp_method_get_param, method, index);
}

Il2CppClass* il2cpp_method_get_class(const MethodInfo *method)
{
    CallIl2CppFun1(il2cpp_method_get_class, method);
}

bool il2cpp_method_has_attribute(const MethodInfo *method, Il2CppClass *attr_class)
{
    CallIl2CppFun2(il2cpp_method_has_attribute, method, attr_class);
}

Il2CppClass* il2cpp_method_get_declaring_type(const MethodInfo* method)
{
    CallIl2CppFun1(il2cpp_method_get_declaring_type, method);
}

uint32_t il2cpp_method_get_flags(const MethodInfo *method, uint32_t *iflags)
{
    CallIl2CppFun2(il2cpp_method_get_flags, method, iflags);
}

uint32_t il2cpp_method_get_token(const MethodInfo *method)
{
    CallIl2CppFun1(il2cpp_method_get_token, method);
}

const char *il2cpp_method_get_param_name(const MethodInfo *method, uint32_t index)
{
    CallIl2CppFun2(il2cpp_method_get_param_name, method, index);
}

void il2cpp_profiler_install(Il2CppProfiler *prof, Il2CppProfileFunc shutdown_callback)
{
    CallIl2CppFun2(il2cpp_profiler_install, prof, shutdown_callback);
}

void il2cpp_profiler_set_events(Il2CppProfileFlags events)
{
    CallIl2CppFun1(il2cpp_profiler_set_events, events);
}

void il2cpp_profiler_install_enter_leave(Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave)
{
    CallIl2CppFun2(il2cpp_profiler_install_enter_leave, enter, fleave);
}

void il2cpp_profiler_install_allocation(Il2CppProfileAllocFunc callback)
{
    CallIl2CppFun1(il2cpp_profiler_install_allocation, callback);
}

void il2cpp_profiler_install_gc(Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback)
{
    CallIl2CppFun2(il2cpp_profiler_install_gc, callback, heap_resize_callback);
}

void il2cpp_profiler_install_fileio(Il2CppProfileFileIOFunc callback)
{
    CallIl2CppFun1(il2cpp_profiler_install_fileio, callback);
}

void il2cpp_profiler_install_thread(Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end)
{
    CallIl2CppFun2(il2cpp_profiler_install_thread, start, end);
}


const char* il2cpp_property_get_name(PropertyInfo *prop)
{
    CallIl2CppFun1(il2cpp_property_get_name, prop);
}

const MethodInfo* il2cpp_property_get_get_method(PropertyInfo *prop)
{
    CallIl2CppFun1(il2cpp_property_get_get_method, prop);
}

const MethodInfo* il2cpp_property_get_set_method(PropertyInfo *prop)
{
    CallIl2CppFun1(il2cpp_property_get_set_method, prop);
}

Il2CppClass* il2cpp_property_get_parent(PropertyInfo *prop)
{
    CallIl2CppFun1(il2cpp_property_get_parent, prop);
}

uint32_t il2cpp_property_get_flags(PropertyInfo *prop)
{
    CallIl2CppFun1(il2cpp_property_get_flags, prop);
}

// object

Il2CppClass* il2cpp_object_get_class(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_object_get_class, obj);
}

uint32_t il2cpp_object_get_size(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_object_get_size, obj);
}

const MethodInfo* il2cpp_object_get_virtual_method(Il2CppObject *obj, const MethodInfo *method)
{
    CallIl2CppFun2(il2cpp_object_get_virtual_method, obj, method);
}

Il2CppObject* il2cpp_object_new(const Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_object_new, klass);
}

void* il2cpp_object_unbox(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_object_unbox, obj);
}

Il2CppObject* il2cpp_value_box(Il2CppClass *klass, void* data)
{
    CallIl2CppFun2(il2cpp_value_box, klass, data);
}

// monitor
void il2cpp_monitor_enter(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_monitor_enter, obj);
}

bool il2cpp_monitor_try_enter(Il2CppObject* obj, uint32_t timeout)
{
    CallIl2CppFun2(il2cpp_monitor_try_enter, obj, timeout);
}

void il2cpp_monitor_exit(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_monitor_exit, obj);
}

void il2cpp_monitor_pulse(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_monitor_pulse, obj);
}

void il2cpp_monitor_pulse_all(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_monitor_pulse_all, obj);
}

void il2cpp_monitor_wait(Il2CppObject* obj)
{
    CallIl2CppFun1(il2cpp_monitor_wait, obj);
}

bool il2cpp_monitor_try_wait(Il2CppObject* obj, uint32_t timeout)
{
    CallIl2CppFun2(il2cpp_monitor_try_wait, obj, timeout);
}

// runtime

Il2CppObject* il2cpp_runtime_invoke_convert_args(const MethodInfo *method, void *obj, Il2CppObject **params, int paramCount, Il2CppException **exc)
{
    CallIl2CppFun5(il2cpp_runtime_invoke_convert_args, method, obj, params, paramCount, exc);
}

Il2CppObject* il2cpp_runtime_invoke(const MethodInfo *method,
                                    void *obj, void **params, Il2CppException **exc)
{
    CallIl2CppFun4(il2cpp_runtime_invoke, method, obj, params, exc);
}

void il2cpp_runtime_class_init(Il2CppClass* klass)
{
    CallIl2CppFun1(il2cpp_runtime_class_init, klass);
}

void il2cpp_runtime_object_init(Il2CppObject *obj)
{
    CallIl2CppFun1(il2cpp_runtime_object_init, obj);
}

void il2cpp_runtime_object_init_exception(Il2CppObject *obj, Il2CppException **exc)
{
    CallIl2CppFun2(il2cpp_runtime_object_init_exception, obj, exc);
}

void il2cpp_runtime_unhandled_exception_policy_set(Il2CppRuntimeUnhandledExceptionPolicy value)
{
    CallIl2CppFun1(il2cpp_runtime_unhandled_exception_policy_set, value);
}

// string

int32_t il2cpp_string_length(Il2CppString* str)
{
    CallIl2CppFun1(il2cpp_string_length, str);
}

Il2CppChar* il2cpp_string_chars(Il2CppString* str)
{
    CallIl2CppFun1(il2cpp_string_chars, str);
}

// Same as il2cpp_string_new_wrapper, because other normally takes a domain
Il2CppString* il2cpp_string_new(const char* str)
{
    CallIl2CppFun1(il2cpp_string_new, str);
}

Il2CppString* il2cpp_string_new_wrapper(const char* str)
{
    CallIl2CppFun1(il2cpp_string_new_wrapper, str);
}

Il2CppString* il2cpp_string_new_utf16(const Il2CppChar *text, int32_t len)
{
    CallIl2CppFun2(il2cpp_string_new_utf16, text, len);
}

Il2CppString* il2cpp_string_new_len(const char* str, uint32_t length)
{
    CallIl2CppFun2(il2cpp_string_new_len, str, length);
}

Il2CppString* il2cpp_string_intern(Il2CppString* str)
{
    CallIl2CppFun1(il2cpp_string_intern, str);
}

Il2CppString* il2cpp_string_is_interned(Il2CppString* str)
{
    CallIl2CppFun1(il2cpp_string_is_interned, str);
}

// thread

Il2CppThread *il2cpp_thread_current()
{
    CallIl2CppFun0(il2cpp_thread_current);
}

Il2CppThread *il2cpp_thread_attach(Il2CppDomain *domain)
{
    CallIl2CppFun1(il2cpp_thread_attach, domain);
}

void il2cpp_thread_detach(Il2CppThread *thread)
{
    CallIl2CppFun1(il2cpp_thread_detach, thread);
}

Il2CppThread **il2cpp_thread_get_all_attached_threads(size_t *size)
{
    CallIl2CppFun1(il2cpp_thread_get_all_attached_threads, size);
}

bool il2cpp_is_vm_thread(Il2CppThread *thread)
{
    CallIl2CppFun1(il2cpp_is_vm_thread, thread);
}

// stacktrace

void il2cpp_current_thread_walk_frame_stack(Il2CppFrameWalkFunc func, void* user_data)
{
    CallIl2CppFun2(il2cpp_current_thread_walk_frame_stack, func, user_data);
}

void il2cpp_thread_walk_frame_stack(Il2CppThread *thread, Il2CppFrameWalkFunc func, void *user_data)
{
    CallIl2CppFun3(il2cpp_thread_walk_frame_stack, thread, func, user_data);
}

bool il2cpp_current_thread_get_top_frame(Il2CppStackFrameInfo* frame)
{
    CallIl2CppFun1(il2cpp_current_thread_get_top_frame, frame);
}

bool il2cpp_thread_get_top_frame(Il2CppThread* thread, Il2CppStackFrameInfo* frame)
{
    CallIl2CppFun2(il2cpp_thread_get_top_frame, thread, frame);
}

bool il2cpp_current_thread_get_frame_at(int32_t offset, Il2CppStackFrameInfo* frame)
{
    CallIl2CppFun2(il2cpp_current_thread_get_frame_at, offset, frame);
}

bool il2cpp_thread_get_frame_at(Il2CppThread* thread, int32_t offset, Il2CppStackFrameInfo* frame)
{
    CallIl2CppFun3(il2cpp_thread_get_frame_at, thread, offset, frame);
}

int32_t il2cpp_current_thread_get_stack_depth()
{
    CallIl2CppFun0(il2cpp_current_thread_get_stack_depth);
}

int32_t il2cpp_thread_get_stack_depth(Il2CppThread *thread)
{
    CallIl2CppFun1(il2cpp_thread_get_stack_depth, thread);
}

// type

Il2CppObject* il2cpp_type_get_object(const Il2CppType *type)
{
    CallIl2CppFun1(il2cpp_type_get_object, type);
}

int il2cpp_type_get_type(const Il2CppType *type)
{
    CallIl2CppFun1(il2cpp_type_get_type, type);
}

Il2CppClass* il2cpp_type_get_class_or_element_class(const Il2CppType *type)
{
    CallIl2CppFun1(il2cpp_type_get_class_or_element_class, type);
}

char* il2cpp_type_get_name(const Il2CppType *type)
{
    CallIl2CppFun1(il2cpp_type_get_name, type);
}

char* il2cpp_type_get_assembly_qualified_name(const Il2CppType * type)
{
    CallIl2CppFun1(il2cpp_type_get_assembly_qualified_name, type);
}

bool il2cpp_type_is_byref(const Il2CppType *type)
{
    CallIl2CppFun1(il2cpp_type_is_byref, type);
}

uint32_t il2cpp_type_get_attrs(const Il2CppType *type)
{
    CallIl2CppFun1(il2cpp_type_get_attrs, type);
}

bool il2cpp_type_equals(const Il2CppType* type, const Il2CppType *otherType)
{
    CallIl2CppFun2(il2cpp_type_equals, type, otherType);
}

// image

const Il2CppAssembly* il2cpp_image_get_assembly(const Il2CppImage *image)
{
    CallIl2CppFun1(il2cpp_image_get_assembly, image);
}

const char* il2cpp_image_get_name(const Il2CppImage *image)
{
    CallIl2CppFun1(il2cpp_image_get_name, image);
}

const char* il2cpp_image_get_filename(const Il2CppImage *image)
{
    CallIl2CppFun1(il2cpp_image_get_filename, image);
}

const MethodInfo* il2cpp_image_get_entry_point(const Il2CppImage *image)
{
    CallIl2CppFun1(il2cpp_image_get_entry_point, image);
}

size_t il2cpp_image_get_class_count(const Il2CppImage * image)
{
    CallIl2CppFun1(il2cpp_image_get_class_count, image);
}

const Il2CppClass* il2cpp_image_get_class(const Il2CppImage * image, size_t index)
{
    CallIl2CppFun2(il2cpp_image_get_class, image, index);
}

Il2CppManagedMemorySnapshot* il2cpp_capture_memory_snapshot()
{
    CallIl2CppFun0(il2cpp_capture_memory_snapshot);
}

void il2cpp_free_captured_memory_snapshot(Il2CppManagedMemorySnapshot* snapshot)
{
    CallIl2CppFun1(il2cpp_free_captured_memory_snapshot, snapshot);
}

void il2cpp_set_find_plugin_callback(Il2CppSetFindPlugInCallback method)
{
    CallIl2CppFun1(il2cpp_set_find_plugin_callback, method);
}

// Logging

void il2cpp_register_log_callback(Il2CppLogCallback method)
{
    CallIl2CppFun1(il2cpp_register_log_callback, method);
}

// Debugger
void il2cpp_debugger_set_agent_options(const char* options)
{
    CallIl2CppFun1(il2cpp_debugger_set_agent_options, options);
}

bool il2cpp_is_debugger_attached()
{
    CallIl2CppFun0(il2cpp_is_debugger_attached);
}

void il2cpp_unity_install_unitytls_interface(const void* unitytlsInterfaceStruct)
{
    CallIl2CppFun1(il2cpp_unity_install_unitytls_interface, unitytlsInterfaceStruct);
}

// Custom Attributes
Il2CppCustomAttrInfo* il2cpp_custom_attrs_from_class(Il2CppClass *klass)
{
    CallIl2CppFun1(il2cpp_custom_attrs_from_class, klass);
}

Il2CppCustomAttrInfo* il2cpp_custom_attrs_from_method(const MethodInfo * method)
{
    CallIl2CppFun1(il2cpp_custom_attrs_from_method, method);
}

bool il2cpp_custom_attrs_has_attr(Il2CppCustomAttrInfo *ainfo, Il2CppClass *attr_klass)
{
    CallIl2CppFun2(il2cpp_custom_attrs_has_attr, ainfo, attr_klass);
}

Il2CppObject* il2cpp_custom_attrs_get_attr(Il2CppCustomAttrInfo *ainfo, Il2CppClass *attr_klass)
{
    CallIl2CppFun2(il2cpp_custom_attrs_get_attr, ainfo, attr_klass);
}

Il2CppArray*  il2cpp_custom_attrs_construct(Il2CppCustomAttrInfo *ainfo)
{
    CallIl2CppFun1(il2cpp_custom_attrs_construct, ainfo);
}

void il2cpp_custom_attrs_free(Il2CppCustomAttrInfo *ainfo)
{
    // nothing to free, we cache everything
    CallIl2CppFun1(il2cpp_custom_attrs_free, ainfo);
}



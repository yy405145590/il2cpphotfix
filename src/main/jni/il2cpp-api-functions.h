//
// Created by Administrator on 2019/5/14.
//

#ifndef TEST_UPDATE_IL2CPP_API_FUNCTIONS_H
#define TEST_UPDATE_IL2CPP_API_FUNCTIONS_H
#include <stdint.h>
#include <stddef.h>
#ifndef DO_API_NO_RETURN
#define DO_API_NO_RETURN(r, n, p) DO_API(r,n,p)
#endif
typedef void (*Il2CppMethodPointer)();
typedef uint16_t Il2CppChar;
typedef struct
{
void* (*malloc_func)(size_t size);
void* (*aligned_malloc_func)(size_t size, size_t alignment);
void (*free_func)(void *ptr);
void (*aligned_free_func)(void *ptr);
void* (*calloc_func)(size_t nmemb, size_t size);
void* (*realloc_func)(void *ptr, size_t size);
void* (*aligned_realloc_func)(void *ptr, size_t size, size_t alignment);
} Il2CppMemoryCallbacks;
typedef void Il2CppClass;
typedef void Il2CppArray;
typedef void Il2CppImage;
typedef void Il2CppAssembly;
typedef void Il2CppReflectionType;
typedef void EventInfo;
typedef uintptr_t il2cpp_array_size_t;
typedef void FieldInfo;
typedef void PropertyInfo;
typedef void MethodInfo;
typedef void Il2CppType;
typedef enum
{
Stat_VOID,
}Il2CppStat;

typedef enum
{
Event_VOID,
}Il2CppGCEvent;

typedef enum
{
Kind_VOID,
}Il2CppProfileFileIOKind;

typedef enum
{
Policy_VOID,
}Il2CppRuntimeUnhandledExceptionPolicy;

typedef enum
{
    Flags_VOID,
} Il2CppProfileFlags;

typedef void Il2CppDomain;
typedef void Il2CppException;
typedef void Il2CppObject;
typedef void Il2CppReflectionMethod;
typedef void Il2CppProfiler;
typedef void Il2CppString;
typedef void Il2CppThread;
typedef void Il2CppManagedMemorySnapshot;
typedef void Il2CppCustomAttrInfo;
typedef void Il2CppStackFrameInfo;
typedef char Il2CppNativeChar;
typedef void (*il2cpp_register_object_callback)(Il2CppObject** arr, int size, void* userdata);
typedef void (*il2cpp_WorldChangedCallback)();
typedef void (*Il2CppFrameWalkFunc) (const Il2CppStackFrameInfo *info, void *user_data);
typedef void (*Il2CppProfileFunc) (Il2CppProfiler* prof);
typedef void (*Il2CppProfileMethodFunc) (Il2CppProfiler* prof, const MethodInfo *method);
typedef void (*Il2CppProfileAllocFunc) (Il2CppProfiler* prof, Il2CppObject *obj, Il2CppClass *klass);
typedef void (*Il2CppProfileGCFunc) (Il2CppProfiler* prof, Il2CppGCEvent event, int generation);
typedef void (*Il2CppProfileGCResizeFunc) (Il2CppProfiler* prof, int64_t new_size);
typedef void (*Il2CppProfileFileIOFunc) (Il2CppProfiler* prof, Il2CppProfileFileIOKind kind, int count);
typedef void (*Il2CppProfileThreadFunc) (Il2CppProfiler *prof, unsigned long tid);
typedef void (*Il2CppLogCallback)(const char*);
typedef const Il2CppNativeChar* (*Il2CppSetFindPlugInCallback)(const Il2CppNativeChar*);

#define DEFINE_IL2CPP_FUN(a, b, c)\
DO_API(a, b, c);\
typedef a (*p_##b)c;

DEFINE_IL2CPP_FUN(void, il2cpp_init, (const char* domain_name));
DEFINE_IL2CPP_FUN(void, il2cpp_init_utf16, (const Il2CppChar * domain_name));
DEFINE_IL2CPP_FUN(void, il2cpp_shutdown, ());
DEFINE_IL2CPP_FUN(void, il2cpp_set_config_dir, (const char *config_path));
DEFINE_IL2CPP_FUN(void, il2cpp_set_data_dir, (const char *data_path));
DEFINE_IL2CPP_FUN(void, il2cpp_set_temp_dir, (const char *temp_path));
DEFINE_IL2CPP_FUN(void, il2cpp_set_commandline_arguments, (int argc, const char* const argv[], const char* basedir));
DEFINE_IL2CPP_FUN(void, il2cpp_set_commandline_arguments_utf16, (int argc, const Il2CppChar * const argv[], const char* basedir));
DEFINE_IL2CPP_FUN(void, il2cpp_set_config_utf16, (const Il2CppChar * executablePath));
DEFINE_IL2CPP_FUN(void, il2cpp_set_config, (const char* executablePath));

DEFINE_IL2CPP_FUN(void, il2cpp_set_memory_callbacks, (Il2CppMemoryCallbacks * callbacks));
DEFINE_IL2CPP_FUN(const Il2CppImage*, il2cpp_get_corlib, ());
DEFINE_IL2CPP_FUN(void, il2cpp_add_internal_call, (const char* name, Il2CppMethodPointer method));
DEFINE_IL2CPP_FUN(Il2CppMethodPointer, il2cpp_resolve_icall, (const char* name));

DEFINE_IL2CPP_FUN(void*, il2cpp_alloc, (size_t size));
DEFINE_IL2CPP_FUN(void, il2cpp_free, (void* ptr));

// array
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_array_class_get, (Il2CppClass * element_class, uint32_t rank));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_array_length, (Il2CppArray * array));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_array_get_byte_length, (Il2CppArray * array));
DEFINE_IL2CPP_FUN(Il2CppArray*, il2cpp_array_new, (Il2CppClass * elementTypeInfo, il2cpp_array_size_t length));
DEFINE_IL2CPP_FUN(Il2CppArray*, il2cpp_array_new_specific, (Il2CppClass * arrayTypeInfo, il2cpp_array_size_t length));
DEFINE_IL2CPP_FUN(Il2CppArray*, il2cpp_array_new_full, (Il2CppClass * array_class, il2cpp_array_size_t * lengths, il2cpp_array_size_t * lower_bounds));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_bounded_array_class_get, (Il2CppClass * element_class, uint32_t rank, bool bounded));
DEFINE_IL2CPP_FUN(int, il2cpp_array_element_size, (const Il2CppClass * array_class));

// assembly
DEFINE_IL2CPP_FUN(const Il2CppImage*, il2cpp_assembly_get_image, (const Il2CppAssembly * assembly));

// class
DEFINE_IL2CPP_FUN(const Il2CppType*, il2cpp_class_enum_basetype, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_generic, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_inflated, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_assignable_from, (Il2CppClass * klass, Il2CppClass * oklass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_subclass_of, (Il2CppClass * klass, Il2CppClass * klassc, bool check_interfaces));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_has_parent, (Il2CppClass * klass, Il2CppClass * klassc));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_from_il2cpp_type, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_from_name, (const Il2CppImage * image, const char* namespaze, const char *name));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_from_system_type, (Il2CppReflectionType * type));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_get_element_class, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(const EventInfo*, il2cpp_class_get_events, (Il2CppClass * klass, void* *iter));
DEFINE_IL2CPP_FUN(FieldInfo*, il2cpp_class_get_fields, (Il2CppClass * klass, void* *iter));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_get_nested_types, (Il2CppClass * klass, void* *iter));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_get_interfaces, (Il2CppClass * klass, void* *iter));
DEFINE_IL2CPP_FUN(const PropertyInfo*, il2cpp_class_get_properties, (Il2CppClass * klass, void* *iter));
DEFINE_IL2CPP_FUN(const PropertyInfo*, il2cpp_class_get_property_from_name, (Il2CppClass * klass, const char *name));
DEFINE_IL2CPP_FUN(FieldInfo*, il2cpp_class_get_field_from_name, (Il2CppClass * klass, const char *name));
DEFINE_IL2CPP_FUN(const MethodInfo*, il2cpp_class_get_methods, (Il2CppClass * klass, void* *iter));
DEFINE_IL2CPP_FUN(const MethodInfo*, il2cpp_class_get_method_from_name, (Il2CppClass * klass, const char* name, int argsCount));
DEFINE_IL2CPP_FUN(const char*, il2cpp_class_get_name, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(const char*, il2cpp_class_get_namespace, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_get_parent, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_get_declaring_type, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(int32_t, il2cpp_class_instance_size, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(size_t, il2cpp_class_num_fields, (const Il2CppClass * enumKlass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_valuetype, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(int32_t, il2cpp_class_value_size, (Il2CppClass * klass, uint32_t * align));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_blittable, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(int, il2cpp_class_get_flags, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_abstract, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_interface, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(int, il2cpp_class_array_element_size, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_class_from_type, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(const Il2CppType*, il2cpp_class_get_type, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_class_get_type_token, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_has_attribute, (Il2CppClass * klass, Il2CppClass * attr_class));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_has_references, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_class_is_enum, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(const Il2CppImage*, il2cpp_class_get_image, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(const char*, il2cpp_class_get_assemblyname, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(int, il2cpp_class_get_rank, (const Il2CppClass * klass));

// testing only
DEFINE_IL2CPP_FUN(size_t, il2cpp_class_get_bitmap_size, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(void, il2cpp_class_get_bitmap, (Il2CppClass * klass, size_t * bitmap));

// stats
DEFINE_IL2CPP_FUN(bool, il2cpp_stats_dump_to_file, (const char *path));
DEFINE_IL2CPP_FUN(uint64_t, il2cpp_stats_get_value, (Il2CppStat stat));

// domain
DEFINE_IL2CPP_FUN(Il2CppDomain*, il2cpp_domain_get, ());
DEFINE_IL2CPP_FUN(const Il2CppAssembly*, il2cpp_domain_assembly_open, (Il2CppDomain * domain, const char* name));
DEFINE_IL2CPP_FUN(const Il2CppAssembly**, il2cpp_domain_get_assemblies, (const Il2CppDomain * domain, size_t * size));

// exception
DEFINE_IL2CPP_FUN(void, il2cpp_raise_exception, (Il2CppException*));
DEFINE_IL2CPP_FUN(Il2CppException*, il2cpp_exception_from_name_msg, (const Il2CppImage * image, const char *name_space, const char *name, const char *msg));
DEFINE_IL2CPP_FUN(Il2CppException*, il2cpp_get_exception_argument_null, (const char *arg));
DEFINE_IL2CPP_FUN(void, il2cpp_format_exception, (const Il2CppException * ex, char* message, int message_size));
DEFINE_IL2CPP_FUN(void, il2cpp_format_stack_trace, (const Il2CppException * ex, char* output, int output_size));
DEFINE_IL2CPP_FUN(void, il2cpp_unhandled_exception, (Il2CppException*));

// field
DEFINE_IL2CPP_FUN(int, il2cpp_field_get_flags, (FieldInfo * field));
DEFINE_IL2CPP_FUN(const char*, il2cpp_field_get_name, (FieldInfo * field));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_field_get_parent, (FieldInfo * field));
DEFINE_IL2CPP_FUN(size_t, il2cpp_field_get_offset, (FieldInfo * field));
DEFINE_IL2CPP_FUN(const Il2CppType*, il2cpp_field_get_type, (FieldInfo * field));
DEFINE_IL2CPP_FUN(void, il2cpp_field_get_value, (Il2CppObject * obj, FieldInfo * field, void *value));
DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_field_get_value_object, (FieldInfo * field, Il2CppObject * obj));
DEFINE_IL2CPP_FUN(bool, il2cpp_field_has_attribute, (FieldInfo * field, Il2CppClass * attr_class));
DEFINE_IL2CPP_FUN(void, il2cpp_field_set_value, (Il2CppObject * obj, FieldInfo * field, void *value));
DEFINE_IL2CPP_FUN(void, il2cpp_field_static_get_value, (FieldInfo * field, void *value));
DEFINE_IL2CPP_FUN(void, il2cpp_field_static_set_value, (FieldInfo * field, void *value));
DEFINE_IL2CPP_FUN(void, il2cpp_field_set_value_object, (Il2CppObject * instance, FieldInfo * field, Il2CppObject * value));

// gc
DEFINE_IL2CPP_FUN(void, il2cpp_gc_collect, (int maxGenerations));
DEFINE_IL2CPP_FUN(int32_t, il2cpp_gc_collect_a_little, ());
DEFINE_IL2CPP_FUN(void, il2cpp_gc_disable, ());
DEFINE_IL2CPP_FUN(void, il2cpp_gc_enable, ());
DEFINE_IL2CPP_FUN(bool, il2cpp_gc_is_disabled, ());
DEFINE_IL2CPP_FUN(int64_t, il2cpp_gc_get_used_size, ());
DEFINE_IL2CPP_FUN(int64_t, il2cpp_gc_get_heap_size, ());
DEFINE_IL2CPP_FUN(void, il2cpp_gc_wbarrier_set_field, (Il2CppObject * obj, void **targetAddress, void *object));

// gchandle
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_gchandle_new, (Il2CppObject * obj, bool pinned));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_gchandle_new_weakref, (Il2CppObject * obj, bool track_resurrection));
DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_gchandle_get_target , (uint32_t gchandle));
DEFINE_IL2CPP_FUN(void, il2cpp_gchandle_free, (uint32_t gchandle));

// liveness
DEFINE_IL2CPP_FUN(void*, il2cpp_unity_liveness_calculation_begin, (Il2CppClass * filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped));
DEFINE_IL2CPP_FUN(void, il2cpp_unity_liveness_calculation_end, (void* state));
DEFINE_IL2CPP_FUN(void, il2cpp_unity_liveness_calculation_from_root, (Il2CppObject * root, void* state));
DEFINE_IL2CPP_FUN(void, il2cpp_unity_liveness_calculation_from_statics, (void* state));

// method
DEFINE_IL2CPP_FUN(const Il2CppType*, il2cpp_method_get_return_type, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_method_get_declaring_type, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(const char*, il2cpp_method_get_name, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(const MethodInfo*, il2cpp_method_get_from_reflection, (const Il2CppReflectionMethod * method));
DEFINE_IL2CPP_FUN(Il2CppReflectionMethod*, il2cpp_method_get_object, (const MethodInfo * method, Il2CppClass * refclass));
DEFINE_IL2CPP_FUN(bool, il2cpp_method_is_generic, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(bool, il2cpp_method_is_inflated, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(bool, il2cpp_method_is_instance, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_method_get_param_count, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(const Il2CppType*, il2cpp_method_get_param, (const MethodInfo * method, uint32_t index));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_method_get_class, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(bool, il2cpp_method_has_attribute, (const MethodInfo * method, Il2CppClass * attr_class));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_method_get_flags, (const MethodInfo * method, uint32_t * iflags));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_method_get_token, (const MethodInfo * method));
DEFINE_IL2CPP_FUN(const char*, il2cpp_method_get_param_name, (const MethodInfo * method, uint32_t index));

DEFINE_IL2CPP_FUN(void, il2cpp_profiler_install, (Il2CppProfiler * prof, Il2CppProfileFunc shutdown_callback));
DEFINE_IL2CPP_FUN(void, il2cpp_profiler_set_events, (Il2CppProfileFlags events));
DEFINE_IL2CPP_FUN(void, il2cpp_profiler_install_enter_leave, (Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave));
DEFINE_IL2CPP_FUN(void, il2cpp_profiler_install_allocation, (Il2CppProfileAllocFunc callback));
DEFINE_IL2CPP_FUN(void, il2cpp_profiler_install_gc, (Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback));
DEFINE_IL2CPP_FUN(void, il2cpp_profiler_install_fileio, (Il2CppProfileFileIOFunc callback));
DEFINE_IL2CPP_FUN(void, il2cpp_profiler_install_thread, (Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end));


// property
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_property_get_flags, (PropertyInfo * prop));
DEFINE_IL2CPP_FUN(const MethodInfo*, il2cpp_property_get_get_method, (PropertyInfo * prop));
DEFINE_IL2CPP_FUN(const MethodInfo*, il2cpp_property_get_set_method, (PropertyInfo * prop));
DEFINE_IL2CPP_FUN(const char*, il2cpp_property_get_name, (PropertyInfo * prop));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_property_get_parent, (PropertyInfo * prop));

// object
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_object_get_class, (Il2CppObject * obj));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_object_get_size, (Il2CppObject * obj));
DEFINE_IL2CPP_FUN(const MethodInfo*, il2cpp_object_get_virtual_method, (Il2CppObject * obj, const MethodInfo * method));
DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_object_new, (const Il2CppClass * klass));
DEFINE_IL2CPP_FUN(void*, il2cpp_object_unbox, (Il2CppObject * obj));

DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_value_box, (Il2CppClass * klass, void* data));

// monitor
DEFINE_IL2CPP_FUN(void, il2cpp_monitor_enter, (Il2CppObject * obj));
DEFINE_IL2CPP_FUN(bool, il2cpp_monitor_try_enter, (Il2CppObject * obj, uint32_t timeout));
DEFINE_IL2CPP_FUN(void, il2cpp_monitor_exit, (Il2CppObject * obj));
DEFINE_IL2CPP_FUN(void, il2cpp_monitor_pulse, (Il2CppObject * obj));
DEFINE_IL2CPP_FUN(void, il2cpp_monitor_pulse_all, (Il2CppObject * obj));
DEFINE_IL2CPP_FUN(void, il2cpp_monitor_wait, (Il2CppObject * obj));
DEFINE_IL2CPP_FUN(bool, il2cpp_monitor_try_wait, (Il2CppObject * obj, uint32_t timeout));

// runtime
DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_runtime_invoke, (const MethodInfo * method, void *obj, void **params, Il2CppException **exc));
DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_runtime_invoke_convert_args, (const MethodInfo * method, void *obj, Il2CppObject **params, int paramCount, Il2CppException **exc));
DEFINE_IL2CPP_FUN(void, il2cpp_runtime_class_init, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(void, il2cpp_runtime_object_init, (Il2CppObject * obj));

DEFINE_IL2CPP_FUN(void, il2cpp_runtime_object_init_exception, (Il2CppObject * obj, Il2CppException** exc));

DEFINE_IL2CPP_FUN(void, il2cpp_runtime_unhandled_exception_policy_set, (Il2CppRuntimeUnhandledExceptionPolicy value));

// string
DEFINE_IL2CPP_FUN(int32_t, il2cpp_string_length, (Il2CppString * str));
DEFINE_IL2CPP_FUN(Il2CppChar*, il2cpp_string_chars, (Il2CppString * str));
DEFINE_IL2CPP_FUN(Il2CppString*, il2cpp_string_new, (const char* str));
DEFINE_IL2CPP_FUN(Il2CppString*, il2cpp_string_new_len, (const char* str, uint32_t length));
DEFINE_IL2CPP_FUN(Il2CppString*, il2cpp_string_new_utf16, (const Il2CppChar * text, int32_t len));
DEFINE_IL2CPP_FUN(Il2CppString*, il2cpp_string_new_wrapper, (const char* str));
DEFINE_IL2CPP_FUN(Il2CppString*, il2cpp_string_intern, (Il2CppString * str));
DEFINE_IL2CPP_FUN(Il2CppString*, il2cpp_string_is_interned, (Il2CppString * str));

// thread
DEFINE_IL2CPP_FUN(Il2CppThread*, il2cpp_thread_current, ());
DEFINE_IL2CPP_FUN(Il2CppThread*, il2cpp_thread_attach, (Il2CppDomain * domain));
DEFINE_IL2CPP_FUN(void, il2cpp_thread_detach, (Il2CppThread * thread));

DEFINE_IL2CPP_FUN(Il2CppThread**, il2cpp_thread_get_all_attached_threads, (size_t * size));
DEFINE_IL2CPP_FUN(bool, il2cpp_is_vm_thread, (Il2CppThread * thread));

// stacktrace
DEFINE_IL2CPP_FUN(void, il2cpp_current_thread_walk_frame_stack, (Il2CppFrameWalkFunc func, void* user_data));
DEFINE_IL2CPP_FUN(void, il2cpp_thread_walk_frame_stack, (Il2CppThread * thread, Il2CppFrameWalkFunc func, void* user_data));
DEFINE_IL2CPP_FUN(bool, il2cpp_current_thread_get_top_frame, (Il2CppStackFrameInfo * frame));
DEFINE_IL2CPP_FUN(bool, il2cpp_thread_get_top_frame, (Il2CppThread * thread, Il2CppStackFrameInfo * frame));
DEFINE_IL2CPP_FUN(bool, il2cpp_current_thread_get_frame_at, (int32_t offset, Il2CppStackFrameInfo * frame));
DEFINE_IL2CPP_FUN(bool, il2cpp_thread_get_frame_at, (Il2CppThread * thread, int32_t offset, Il2CppStackFrameInfo * frame));
DEFINE_IL2CPP_FUN(int32_t, il2cpp_current_thread_get_stack_depth, ());
DEFINE_IL2CPP_FUN(int32_t, il2cpp_thread_get_stack_depth, (Il2CppThread * thread));

// type
DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_type_get_object, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(int, il2cpp_type_get_type, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(Il2CppClass*, il2cpp_type_get_class_or_element_class, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(char*, il2cpp_type_get_name, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(bool, il2cpp_type_is_byref, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(uint32_t, il2cpp_type_get_attrs, (const Il2CppType * type));
DEFINE_IL2CPP_FUN(bool, il2cpp_type_equals, (const Il2CppType * type, const Il2CppType * otherType));
DEFINE_IL2CPP_FUN(char*, il2cpp_type_get_assembly_qualified_name, (const Il2CppType * type));

// image
DEFINE_IL2CPP_FUN(const Il2CppAssembly*, il2cpp_image_get_assembly, (const Il2CppImage * image));
DEFINE_IL2CPP_FUN(const char*, il2cpp_image_get_name, (const Il2CppImage * image));
DEFINE_IL2CPP_FUN(const char*, il2cpp_image_get_filename, (const Il2CppImage * image));
DEFINE_IL2CPP_FUN(const MethodInfo*, il2cpp_image_get_entry_point, (const Il2CppImage * image));

DEFINE_IL2CPP_FUN(size_t, il2cpp_image_get_class_count, (const Il2CppImage * image));
DEFINE_IL2CPP_FUN(const Il2CppClass*, il2cpp_image_get_class, (const Il2CppImage * image, size_t index));

// Memory information
DEFINE_IL2CPP_FUN(Il2CppManagedMemorySnapshot*, il2cpp_capture_memory_snapshot, ());
DEFINE_IL2CPP_FUN(void, il2cpp_free_captured_memory_snapshot, (Il2CppManagedMemorySnapshot * snapshot));

DEFINE_IL2CPP_FUN(void, il2cpp_set_find_plugin_callback, (Il2CppSetFindPlugInCallback method));

// Logging
DEFINE_IL2CPP_FUN(void, il2cpp_register_log_callback, (Il2CppLogCallback method));

// Debugger
DEFINE_IL2CPP_FUN(void, il2cpp_debugger_set_agent_options, (const char* options));
DEFINE_IL2CPP_FUN(bool, il2cpp_is_debugger_attached, ());

// TLS module
DEFINE_IL2CPP_FUN(void, il2cpp_unity_install_unitytls_interface, (const void* unitytlsInterfaceStruct));

// custom attributes
DEFINE_IL2CPP_FUN(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_class, (Il2CppClass * klass));
DEFINE_IL2CPP_FUN(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_method, (const MethodInfo * method));

DEFINE_IL2CPP_FUN(Il2CppObject*, il2cpp_custom_attrs_get_attr, (Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass));
DEFINE_IL2CPP_FUN(bool, il2cpp_custom_attrs_has_attr, (Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass));
DEFINE_IL2CPP_FUN(Il2CppArray*,  il2cpp_custom_attrs_construct, (Il2CppCustomAttrInfo * cinfo));

DEFINE_IL2CPP_FUN(void, il2cpp_custom_attrs_free, (Il2CppCustomAttrInfo * ainfo));

#endif //TEST_UPDATE_IL2CPP_API_FUNCTIONS_H

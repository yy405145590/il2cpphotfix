#include <jni.h>
#include <android/log.h>
#include <string.h>
#include "com_ly_update_HotFixPlugin.h"
#include <dlfcn.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "YY" ,__VA_ARGS__)
#if JNI_FALSE
#if defined(__i386__)
#define JUMPCODE(addr)   asm __volatile__(\
            "nop\n"\
            "push %0\n"\
            "ret\n"\
            :\
            :"m" (addr)\
            :\
            );
#elif defined(__x86_64__)
#define JUMPCODE(addr)    asm __volatile__(\
        "push rax\n"\
        "push rbx\n"\
        "push rcx\n"\
        "push rdx\n"\
        );\
        asm __volatile__(\
        "pop rax\n"\
        "pop rbx\n"\
        "pop rcx\n"\
        "pop rdx\n"\
        "push %0\n"\
        "ret\n"\
        :\
        :"m" (addr)\
        :"rax", "rbx", "rcx", "rdx"\
        );
#elif defined(__aarch64__)
#define JUMPCODE(addr)  \
asm __volatile__(\
"SUB SP, SP, #0x70\n"\
        "STP X0, X1, [SP, #0x10]\n"\
        "STP X2, X3, [SP, #0x20]\n"\
        "STP X4, X5, [SP, #0x30]\n"\
        "STP X6, X7, [SP, #0x40]"\
);\
asm __volatile__(\
"LDP X6, X7, [SP, #0x40]\n"\
        "LDP X4, X5, [SP, #0x30]\n"\
        "LDP X2, X3, [SP, #0x20]\n"\
        "LDP X0, X1, [SP, #0x10]\n"\
        "ADD SP, SP, #0x70\n"\
        "br %0\n"\
        :\
        :"r"(addr)\
        :"x0","x1","x2","x3", "x4" ,"x5", "x6", "x7"\
        );
#else
#define JUMPCODE(addr)  \
asm __volatile__(\
    "STMFD  SP!, {R11, LR}\n"\
    "STMFD SP!, {R5, R6}\n"\
    "MOV R11, SP\n"\
    "SUB   SP, SP, #16\n"\
    "MOV R5, R0\n"\
    :\
    :\
    :\
    );\
    asm __volatile__(\
    "mov R6, R0\n"\
    "ADD SP, SP, #16\n"\
    "MOV R0, R5\n"\
    "nop\n"\
    "BLX R6\n"\
    "MOV SP, R11\n"\
    "LDMFD SP!, {R5, R6}\n"\
    "LDMFD SP!, {R11, PC}\n"\
    :\
    :"r"(addr)\
    :\
    );
#endif


JNIEXPORT jint JNICALL Java_com_ly_update_TestSO_testso(JNIEnv * p1, jclass p2, jint a, jint b)
{
    LOGD("test so %d", a + b);
    return a + b;
}
void * g_pTest = (void*)(&Java_com_ly_update_TestSO_testso);
__attribute((naked)) void Java_com_ly_update_HotFixPlugin_test()
{
    JUMPCODE(g_pTest);
}

#define JUMP_FUN(funname) \
void * g_##funname = nullptr;\
__attribute((naked)) void funname()\
{\
    JUMPCODE(g_##funname);\
};
#ifdef __cplusplus
extern "C" {
#endif
JUMP_FUN(il2cpp_class_from_type)
JUMP_FUN(il2cpp_class_is_valuetype)
JUMP_FUN(il2cpp_domain_get)
JUMP_FUN(il2cpp_monitor_enter)
JUMP_FUN(il2cpp_monitor_exit)
JUMP_FUN(il2cpp_object_unbox)
JUMP_FUN(il2cpp_runtime_invoke)
JUMP_FUN(il2cpp_gc_wbarrier_set_field)
JUMP_FUN(il2cpp_add_internal_call)
JUMP_FUN(il2cpp_alloc)
JUMP_FUN(il2cpp_array_class_get)
JUMP_FUN(il2cpp_array_element_size)
JUMP_FUN(il2cpp_array_get_byte_length)
JUMP_FUN(il2cpp_array_length)
JUMP_FUN(il2cpp_array_new)
JUMP_FUN(il2cpp_array_new_full)
JUMP_FUN(il2cpp_array_new_specific)
JUMP_FUN(il2cpp_assembly_get_image)
JUMP_FUN(il2cpp_bounded_array_class_get)
JUMP_FUN(il2cpp_capture_memory_snapshot)
JUMP_FUN(il2cpp_class_array_element_size)
JUMP_FUN(il2cpp_class_enum_basetype)
JUMP_FUN(il2cpp_class_from_il2cpp_type)
JUMP_FUN(il2cpp_class_from_name)
JUMP_FUN(il2cpp_class_from_system_type)
JUMP_FUN(il2cpp_class_get_assemblyname)
JUMP_FUN(il2cpp_class_get_bitmap)
JUMP_FUN(il2cpp_class_get_bitmap_size)
JUMP_FUN(il2cpp_class_get_declaring_type)
JUMP_FUN(il2cpp_class_get_element_class)
JUMP_FUN(il2cpp_class_get_events)
JUMP_FUN(il2cpp_class_get_field_from_name)
JUMP_FUN(il2cpp_class_get_fields)
JUMP_FUN(il2cpp_class_get_flags)
JUMP_FUN(il2cpp_class_get_image)
JUMP_FUN(il2cpp_class_get_interfaces)
JUMP_FUN(il2cpp_class_get_method_from_name)
JUMP_FUN(il2cpp_class_get_methods)
JUMP_FUN(il2cpp_class_get_name)
JUMP_FUN(il2cpp_class_get_namespace)
JUMP_FUN(il2cpp_class_get_nested_types)
JUMP_FUN(il2cpp_class_get_parent)
JUMP_FUN(il2cpp_class_get_properties)
JUMP_FUN(il2cpp_class_get_property_from_name)
JUMP_FUN(il2cpp_class_get_rank)
JUMP_FUN(il2cpp_class_get_type)
JUMP_FUN(il2cpp_class_get_type_token)
JUMP_FUN(il2cpp_class_has_attribute)
JUMP_FUN(il2cpp_class_has_parent)
JUMP_FUN(il2cpp_class_has_references)
JUMP_FUN(il2cpp_class_instance_size)
JUMP_FUN(il2cpp_class_is_abstract)
JUMP_FUN(il2cpp_class_is_assignable_from)
JUMP_FUN(il2cpp_class_is_blittable)
JUMP_FUN(il2cpp_class_is_enum)
JUMP_FUN(il2cpp_class_is_generic)
JUMP_FUN(il2cpp_class_is_inflated)
JUMP_FUN(il2cpp_class_is_interface)
JUMP_FUN(il2cpp_class_is_subclass_of)
JUMP_FUN(il2cpp_class_num_fields)
JUMP_FUN(il2cpp_class_value_size)
JUMP_FUN(il2cpp_current_thread_get_frame_at)
JUMP_FUN(il2cpp_current_thread_get_stack_depth)
JUMP_FUN(il2cpp_current_thread_get_top_frame)
JUMP_FUN(il2cpp_current_thread_walk_frame_stack)
JUMP_FUN(il2cpp_custom_attrs_construct)
JUMP_FUN(il2cpp_custom_attrs_free)
JUMP_FUN(il2cpp_custom_attrs_from_class)
JUMP_FUN(il2cpp_custom_attrs_from_method)
JUMP_FUN(il2cpp_custom_attrs_get_attr)
JUMP_FUN(il2cpp_custom_attrs_has_attr)
JUMP_FUN(il2cpp_debugger_set_agent_options)
JUMP_FUN(il2cpp_domain_assembly_open)
JUMP_FUN(il2cpp_domain_get_assemblies)
JUMP_FUN(il2cpp_exception_from_name_msg)
JUMP_FUN(il2cpp_field_get_flags)
JUMP_FUN(il2cpp_field_get_name)
JUMP_FUN(il2cpp_field_get_offset)
JUMP_FUN(il2cpp_field_get_parent)
JUMP_FUN(il2cpp_field_get_type)
JUMP_FUN(il2cpp_field_get_value)
JUMP_FUN(il2cpp_field_get_value_object)
JUMP_FUN(il2cpp_field_has_attribute)
JUMP_FUN(il2cpp_field_set_value)
JUMP_FUN(il2cpp_field_set_value_object)
JUMP_FUN(il2cpp_field_static_get_value)
JUMP_FUN(il2cpp_field_static_set_value)
JUMP_FUN(il2cpp_format_exception)
JUMP_FUN(il2cpp_format_stack_trace)
JUMP_FUN(il2cpp_free)
JUMP_FUN(il2cpp_free_captured_memory_snapshot)
JUMP_FUN(il2cpp_gc_collect)
JUMP_FUN(il2cpp_gc_collect_a_little)
JUMP_FUN(il2cpp_gc_disable)
JUMP_FUN(il2cpp_gc_enable)
JUMP_FUN(il2cpp_gc_get_heap_size)
JUMP_FUN(il2cpp_gc_get_used_size)
JUMP_FUN(il2cpp_gc_is_disabled)
JUMP_FUN(il2cpp_gchandle_free)
JUMP_FUN(il2cpp_gchandle_get_target)
JUMP_FUN(il2cpp_gchandle_new)
JUMP_FUN(il2cpp_gchandle_new_weakref)
JUMP_FUN(il2cpp_get_corlib)
JUMP_FUN(il2cpp_get_exception_argument_null)
JUMP_FUN(il2cpp_image_get_assembly)
JUMP_FUN(il2cpp_image_get_class)
JUMP_FUN(il2cpp_image_get_class_count)
JUMP_FUN(il2cpp_image_get_entry_point)
JUMP_FUN(il2cpp_image_get_filename)
JUMP_FUN(il2cpp_image_get_name)
JUMP_FUN(il2cpp_init)
JUMP_FUN(il2cpp_init_utf16)
JUMP_FUN(il2cpp_is_debugger_attached)
JUMP_FUN(il2cpp_is_vm_thread)
JUMP_FUN(il2cpp_method_get_class)
JUMP_FUN(il2cpp_method_get_declaring_type)
JUMP_FUN(il2cpp_method_get_flags)
JUMP_FUN(il2cpp_method_get_from_reflection)
JUMP_FUN(il2cpp_method_get_name)
JUMP_FUN(il2cpp_method_get_object)
JUMP_FUN(il2cpp_method_get_param)
JUMP_FUN(il2cpp_method_get_param_count)
JUMP_FUN(il2cpp_method_get_param_name)
JUMP_FUN(il2cpp_method_get_return_type)
JUMP_FUN(il2cpp_method_get_token)
JUMP_FUN(il2cpp_method_has_attribute)
JUMP_FUN(il2cpp_method_is_generic)
JUMP_FUN(il2cpp_method_is_inflated)
JUMP_FUN(il2cpp_method_is_instance)
JUMP_FUN(il2cpp_monitor_pulse)
JUMP_FUN(il2cpp_monitor_pulse_all)
JUMP_FUN(il2cpp_monitor_try_enter)
JUMP_FUN(il2cpp_monitor_try_wait)
JUMP_FUN(il2cpp_monitor_wait)
JUMP_FUN(il2cpp_object_get_class)
JUMP_FUN(il2cpp_object_get_size)
JUMP_FUN(il2cpp_object_get_virtual_method)
JUMP_FUN(il2cpp_object_new)
JUMP_FUN(il2cpp_profiler_install)
JUMP_FUN(il2cpp_profiler_install_allocation)
JUMP_FUN(il2cpp_profiler_install_enter_leave)
JUMP_FUN(il2cpp_profiler_install_fileio)
JUMP_FUN(il2cpp_profiler_install_gc)
JUMP_FUN(il2cpp_profiler_install_thread)
JUMP_FUN(il2cpp_profiler_set_events)
JUMP_FUN(il2cpp_property_get_flags)
JUMP_FUN(il2cpp_property_get_get_method)
JUMP_FUN(il2cpp_property_get_name)
JUMP_FUN(il2cpp_property_get_parent)
JUMP_FUN(il2cpp_property_get_set_method)
JUMP_FUN(il2cpp_raise_exception)
JUMP_FUN(il2cpp_register_log_callback)
JUMP_FUN(il2cpp_resolve_icall)
JUMP_FUN(il2cpp_runtime_class_init)
JUMP_FUN(il2cpp_runtime_invoke_convert_args)
JUMP_FUN(il2cpp_runtime_object_init)
JUMP_FUN(il2cpp_runtime_object_init_exception)
JUMP_FUN(il2cpp_runtime_unhandled_exception_policy_set)
JUMP_FUN(il2cpp_set_commandline_arguments)
JUMP_FUN(il2cpp_set_commandline_arguments_utf16)
JUMP_FUN(il2cpp_set_config)
JUMP_FUN(il2cpp_set_config_dir)
JUMP_FUN(il2cpp_set_config_utf16)
JUMP_FUN(il2cpp_set_data_dir)
JUMP_FUN(il2cpp_set_find_plugin_callback)
JUMP_FUN(il2cpp_set_memory_callbacks)
JUMP_FUN(il2cpp_set_temp_dir)
JUMP_FUN(il2cpp_shutdown)
JUMP_FUN(il2cpp_stats_dump_to_file)
JUMP_FUN(il2cpp_stats_get_value)
JUMP_FUN(il2cpp_string_chars)
JUMP_FUN(il2cpp_string_intern)
JUMP_FUN(il2cpp_string_is_interned)
JUMP_FUN(il2cpp_string_length)
JUMP_FUN(il2cpp_string_new)
JUMP_FUN(il2cpp_string_new_len)
JUMP_FUN(il2cpp_string_new_utf16)
JUMP_FUN(il2cpp_string_new_wrapper)
JUMP_FUN(il2cpp_thread_attach)
JUMP_FUN(il2cpp_thread_current)
JUMP_FUN(il2cpp_thread_detach)
JUMP_FUN(il2cpp_thread_get_all_attached_threads)
JUMP_FUN(il2cpp_thread_get_frame_at)
JUMP_FUN(il2cpp_thread_get_stack_depth)
JUMP_FUN(il2cpp_thread_get_top_frame)
JUMP_FUN(il2cpp_thread_walk_frame_stack)
JUMP_FUN(il2cpp_type_equals)
JUMP_FUN(il2cpp_type_get_assembly_qualified_name)
JUMP_FUN(il2cpp_type_get_attrs)
JUMP_FUN(il2cpp_type_get_class_or_element_class)
JUMP_FUN(il2cpp_type_get_name)
JUMP_FUN(il2cpp_type_get_object)
JUMP_FUN(il2cpp_type_get_type)
JUMP_FUN(il2cpp_type_is_byref)
JUMP_FUN(il2cpp_unhandled_exception)
JUMP_FUN(il2cpp_unity_install_unitytls_interface)
JUMP_FUN(il2cpp_unity_liveness_calculation_begin)
JUMP_FUN(il2cpp_unity_liveness_calculation_end)
JUMP_FUN(il2cpp_unity_liveness_calculation_from_root)
JUMP_FUN(il2cpp_unity_liveness_calculation_from_statics)
JUMP_FUN(il2cpp_value_box)
#ifdef __cplusplus
}
#endif
#endif
#define DEFIN_ADDR(funname) void * g_##funname = nullptr;
#ifdef __cplusplus
extern "C" {
#endif
DEFIN_ADDR(il2cpp_class_from_type)
DEFIN_ADDR(il2cpp_class_is_valuetype)
DEFIN_ADDR(il2cpp_domain_get)
DEFIN_ADDR(il2cpp_monitor_enter)
DEFIN_ADDR(il2cpp_monitor_exit)
DEFIN_ADDR(il2cpp_object_unbox)
DEFIN_ADDR(il2cpp_runtime_invoke)
DEFIN_ADDR(il2cpp_gc_wbarrier_set_field)
DEFIN_ADDR(il2cpp_add_internal_call)
DEFIN_ADDR(il2cpp_alloc)
DEFIN_ADDR(il2cpp_array_class_get)
DEFIN_ADDR(il2cpp_array_element_size)
DEFIN_ADDR(il2cpp_array_get_byte_length)
DEFIN_ADDR(il2cpp_array_length)
DEFIN_ADDR(il2cpp_array_new)
DEFIN_ADDR(il2cpp_array_new_full)
DEFIN_ADDR(il2cpp_array_new_specific)
DEFIN_ADDR(il2cpp_assembly_get_image)
DEFIN_ADDR(il2cpp_bounded_array_class_get)
DEFIN_ADDR(il2cpp_capture_memory_snapshot)
DEFIN_ADDR(il2cpp_class_array_element_size)
DEFIN_ADDR(il2cpp_class_enum_basetype)
DEFIN_ADDR(il2cpp_class_from_il2cpp_type)
DEFIN_ADDR(il2cpp_class_from_name)
DEFIN_ADDR(il2cpp_class_from_system_type)
DEFIN_ADDR(il2cpp_class_get_assemblyname)
DEFIN_ADDR(il2cpp_class_get_bitmap)
DEFIN_ADDR(il2cpp_class_get_bitmap_size)
DEFIN_ADDR(il2cpp_class_get_declaring_type)
DEFIN_ADDR(il2cpp_class_get_element_class)
DEFIN_ADDR(il2cpp_class_get_events)
DEFIN_ADDR(il2cpp_class_get_field_from_name)
DEFIN_ADDR(il2cpp_class_get_fields)
DEFIN_ADDR(il2cpp_class_get_flags)
DEFIN_ADDR(il2cpp_class_get_image)
DEFIN_ADDR(il2cpp_class_get_interfaces)
DEFIN_ADDR(il2cpp_class_get_method_from_name)
DEFIN_ADDR(il2cpp_class_get_methods)
DEFIN_ADDR(il2cpp_class_get_name)
DEFIN_ADDR(il2cpp_class_get_namespace)
DEFIN_ADDR(il2cpp_class_get_nested_types)
DEFIN_ADDR(il2cpp_class_get_parent)
DEFIN_ADDR(il2cpp_class_get_properties)
DEFIN_ADDR(il2cpp_class_get_property_from_name)
DEFIN_ADDR(il2cpp_class_get_rank)
DEFIN_ADDR(il2cpp_class_get_type)
DEFIN_ADDR(il2cpp_class_get_type_token)
DEFIN_ADDR(il2cpp_class_has_attribute)
DEFIN_ADDR(il2cpp_class_has_parent)
DEFIN_ADDR(il2cpp_class_has_references)
DEFIN_ADDR(il2cpp_class_instance_size)
DEFIN_ADDR(il2cpp_class_is_abstract)
DEFIN_ADDR(il2cpp_class_is_assignable_from)
DEFIN_ADDR(il2cpp_class_is_blittable)
DEFIN_ADDR(il2cpp_class_is_enum)
DEFIN_ADDR(il2cpp_class_is_generic)
DEFIN_ADDR(il2cpp_class_is_inflated)
DEFIN_ADDR(il2cpp_class_is_interface)
DEFIN_ADDR(il2cpp_class_is_subclass_of)
DEFIN_ADDR(il2cpp_class_num_fields)
DEFIN_ADDR(il2cpp_class_value_size)
DEFIN_ADDR(il2cpp_current_thread_get_frame_at)
DEFIN_ADDR(il2cpp_current_thread_get_stack_depth)
DEFIN_ADDR(il2cpp_current_thread_get_top_frame)
DEFIN_ADDR(il2cpp_current_thread_walk_frame_stack)
DEFIN_ADDR(il2cpp_custom_attrs_construct)
DEFIN_ADDR(il2cpp_custom_attrs_free)
DEFIN_ADDR(il2cpp_custom_attrs_from_class)
DEFIN_ADDR(il2cpp_custom_attrs_from_method)
DEFIN_ADDR(il2cpp_custom_attrs_get_attr)
DEFIN_ADDR(il2cpp_custom_attrs_has_attr)
DEFIN_ADDR(il2cpp_debugger_set_agent_options)
DEFIN_ADDR(il2cpp_domain_assembly_open)
DEFIN_ADDR(il2cpp_domain_get_assemblies)
DEFIN_ADDR(il2cpp_exception_from_name_msg)
DEFIN_ADDR(il2cpp_field_get_flags)
DEFIN_ADDR(il2cpp_field_get_name)
DEFIN_ADDR(il2cpp_field_get_offset)
DEFIN_ADDR(il2cpp_field_get_parent)
DEFIN_ADDR(il2cpp_field_get_type)
DEFIN_ADDR(il2cpp_field_get_value)
DEFIN_ADDR(il2cpp_field_get_value_object)
DEFIN_ADDR(il2cpp_field_has_attribute)
DEFIN_ADDR(il2cpp_field_set_value)
DEFIN_ADDR(il2cpp_field_set_value_object)
DEFIN_ADDR(il2cpp_field_static_get_value)
DEFIN_ADDR(il2cpp_field_static_set_value)
DEFIN_ADDR(il2cpp_format_exception)
DEFIN_ADDR(il2cpp_format_stack_trace)
DEFIN_ADDR(il2cpp_free)
DEFIN_ADDR(il2cpp_free_captured_memory_snapshot)
DEFIN_ADDR(il2cpp_gc_collect)
DEFIN_ADDR(il2cpp_gc_collect_a_little)
DEFIN_ADDR(il2cpp_gc_disable)
DEFIN_ADDR(il2cpp_gc_enable)
DEFIN_ADDR(il2cpp_gc_get_heap_size)
DEFIN_ADDR(il2cpp_gc_get_used_size)
DEFIN_ADDR(il2cpp_gc_is_disabled)
DEFIN_ADDR(il2cpp_gchandle_free)
DEFIN_ADDR(il2cpp_gchandle_get_target)
DEFIN_ADDR(il2cpp_gchandle_new)
DEFIN_ADDR(il2cpp_gchandle_new_weakref)
DEFIN_ADDR(il2cpp_get_corlib)
DEFIN_ADDR(il2cpp_get_exception_argument_null)
DEFIN_ADDR(il2cpp_image_get_assembly)
DEFIN_ADDR(il2cpp_image_get_class)
DEFIN_ADDR(il2cpp_image_get_class_count)
DEFIN_ADDR(il2cpp_image_get_entry_point)
DEFIN_ADDR(il2cpp_image_get_filename)
DEFIN_ADDR(il2cpp_image_get_name)
DEFIN_ADDR(il2cpp_init)
DEFIN_ADDR(il2cpp_init_utf16)
DEFIN_ADDR(il2cpp_is_debugger_attached)
DEFIN_ADDR(il2cpp_is_vm_thread)
DEFIN_ADDR(il2cpp_method_get_class)
DEFIN_ADDR(il2cpp_method_get_declaring_type)
DEFIN_ADDR(il2cpp_method_get_flags)
DEFIN_ADDR(il2cpp_method_get_from_reflection)
DEFIN_ADDR(il2cpp_method_get_name)
DEFIN_ADDR(il2cpp_method_get_object)
DEFIN_ADDR(il2cpp_method_get_param)
DEFIN_ADDR(il2cpp_method_get_param_count)
DEFIN_ADDR(il2cpp_method_get_param_name)
DEFIN_ADDR(il2cpp_method_get_return_type)
DEFIN_ADDR(il2cpp_method_get_token)
DEFIN_ADDR(il2cpp_method_has_attribute)
DEFIN_ADDR(il2cpp_method_is_generic)
DEFIN_ADDR(il2cpp_method_is_inflated)
DEFIN_ADDR(il2cpp_method_is_instance)
DEFIN_ADDR(il2cpp_monitor_pulse)
DEFIN_ADDR(il2cpp_monitor_pulse_all)
DEFIN_ADDR(il2cpp_monitor_try_enter)
DEFIN_ADDR(il2cpp_monitor_try_wait)
DEFIN_ADDR(il2cpp_monitor_wait)
DEFIN_ADDR(il2cpp_object_get_class)
DEFIN_ADDR(il2cpp_object_get_size)
DEFIN_ADDR(il2cpp_object_get_virtual_method)
DEFIN_ADDR(il2cpp_object_new)
DEFIN_ADDR(il2cpp_profiler_install)
DEFIN_ADDR(il2cpp_profiler_install_allocation)
DEFIN_ADDR(il2cpp_profiler_install_enter_leave)
DEFIN_ADDR(il2cpp_profiler_install_fileio)
DEFIN_ADDR(il2cpp_profiler_install_gc)
DEFIN_ADDR(il2cpp_profiler_install_thread)
DEFIN_ADDR(il2cpp_profiler_set_events)
DEFIN_ADDR(il2cpp_property_get_flags)
DEFIN_ADDR(il2cpp_property_get_get_method)
DEFIN_ADDR(il2cpp_property_get_name)
DEFIN_ADDR(il2cpp_property_get_parent)
DEFIN_ADDR(il2cpp_property_get_set_method)
DEFIN_ADDR(il2cpp_raise_exception)
DEFIN_ADDR(il2cpp_register_log_callback)
DEFIN_ADDR(il2cpp_resolve_icall)
DEFIN_ADDR(il2cpp_runtime_class_init)
DEFIN_ADDR(il2cpp_runtime_invoke_convert_args)
DEFIN_ADDR(il2cpp_runtime_object_init)
DEFIN_ADDR(il2cpp_runtime_object_init_exception)
DEFIN_ADDR(il2cpp_runtime_unhandled_exception_policy_set)
DEFIN_ADDR(il2cpp_set_commandline_arguments)
DEFIN_ADDR(il2cpp_set_commandline_arguments_utf16)
DEFIN_ADDR(il2cpp_set_config)
DEFIN_ADDR(il2cpp_set_config_dir)
DEFIN_ADDR(il2cpp_set_config_utf16)
DEFIN_ADDR(il2cpp_set_data_dir)
DEFIN_ADDR(il2cpp_set_find_plugin_callback)
DEFIN_ADDR(il2cpp_set_memory_callbacks)
DEFIN_ADDR(il2cpp_set_temp_dir)
DEFIN_ADDR(il2cpp_shutdown)
DEFIN_ADDR(il2cpp_stats_dump_to_file)
DEFIN_ADDR(il2cpp_stats_get_value)
DEFIN_ADDR(il2cpp_string_chars)
DEFIN_ADDR(il2cpp_string_intern)
DEFIN_ADDR(il2cpp_string_is_interned)
DEFIN_ADDR(il2cpp_string_length)
DEFIN_ADDR(il2cpp_string_new)
DEFIN_ADDR(il2cpp_string_new_len)
DEFIN_ADDR(il2cpp_string_new_utf16)
DEFIN_ADDR(il2cpp_string_new_wrapper)
DEFIN_ADDR(il2cpp_thread_attach)
DEFIN_ADDR(il2cpp_thread_current)
DEFIN_ADDR(il2cpp_thread_detach)
DEFIN_ADDR(il2cpp_thread_get_all_attached_threads)
DEFIN_ADDR(il2cpp_thread_get_frame_at)
DEFIN_ADDR(il2cpp_thread_get_stack_depth)
DEFIN_ADDR(il2cpp_thread_get_top_frame)
DEFIN_ADDR(il2cpp_thread_walk_frame_stack)
DEFIN_ADDR(il2cpp_type_equals)
DEFIN_ADDR(il2cpp_type_get_assembly_qualified_name)
DEFIN_ADDR(il2cpp_type_get_attrs)
DEFIN_ADDR(il2cpp_type_get_class_or_element_class)
DEFIN_ADDR(il2cpp_type_get_name)
DEFIN_ADDR(il2cpp_type_get_object)
DEFIN_ADDR(il2cpp_type_get_type)
DEFIN_ADDR(il2cpp_type_is_byref)
DEFIN_ADDR(il2cpp_unhandled_exception)
DEFIN_ADDR(il2cpp_unity_install_unitytls_interface)
DEFIN_ADDR(il2cpp_unity_liveness_calculation_begin)
DEFIN_ADDR(il2cpp_unity_liveness_calculation_end)
DEFIN_ADDR(il2cpp_unity_liveness_calculation_from_root)
DEFIN_ADDR(il2cpp_unity_liveness_calculation_from_statics)
DEFIN_ADDR(il2cpp_value_box)
#ifdef __cplusplus
}
#endif
typedef void (*UpdateMetaFun)(const char*) ;
void InitUpdate(const char* ilpath, const char* pMetaPath)
{
    void* pIl2cppModule = dlopen(ilpath, RTLD_LOCAL);
    if(pIl2cppModule == nullptr)
    {
        LOGD("il2cpp:%s can't load", ilpath);
        return;
    }
    if(pMetaPath != nullptr)
    {
        char* dupMetaPath = strdup(pMetaPath);
        UpdateMetaFun pSet_meta_update_path = (UpdateMetaFun)dlsym(pIl2cppModule, "il2cpp_set_update_meta_filename");
        if(pSet_meta_update_path != nullptr)
        {
            pSet_meta_update_path(dupMetaPath);
        }
    }

#define GETFUNADDR(funname) g_##funname = dlsym(pIl2cppModule, ""#funname);
    GETFUNADDR(il2cpp_class_from_type)
    GETFUNADDR(il2cpp_class_is_valuetype)
    GETFUNADDR(il2cpp_domain_get)
    GETFUNADDR(il2cpp_monitor_enter)
    GETFUNADDR(il2cpp_monitor_exit)
    GETFUNADDR(il2cpp_object_unbox)
    GETFUNADDR(il2cpp_runtime_invoke)
    GETFUNADDR(il2cpp_gc_wbarrier_set_field)
    GETFUNADDR(il2cpp_add_internal_call)
    GETFUNADDR(il2cpp_alloc)
    GETFUNADDR(il2cpp_array_class_get)
    GETFUNADDR(il2cpp_array_element_size)
    GETFUNADDR(il2cpp_array_get_byte_length)
    GETFUNADDR(il2cpp_array_length)
    GETFUNADDR(il2cpp_array_new)
    GETFUNADDR(il2cpp_array_new_full)
    GETFUNADDR(il2cpp_array_new_specific)
    GETFUNADDR(il2cpp_assembly_get_image)
    GETFUNADDR(il2cpp_bounded_array_class_get)
    GETFUNADDR(il2cpp_capture_memory_snapshot)
    GETFUNADDR(il2cpp_class_array_element_size)
    GETFUNADDR(il2cpp_class_enum_basetype)
    GETFUNADDR(il2cpp_class_from_il2cpp_type)
    GETFUNADDR(il2cpp_class_from_name)
    GETFUNADDR(il2cpp_class_from_system_type)
    GETFUNADDR(il2cpp_class_get_assemblyname)
    GETFUNADDR(il2cpp_class_get_bitmap)
    GETFUNADDR(il2cpp_class_get_bitmap_size)
    GETFUNADDR(il2cpp_class_get_declaring_type)
    GETFUNADDR(il2cpp_class_get_element_class)
    GETFUNADDR(il2cpp_class_get_events)
    GETFUNADDR(il2cpp_class_get_field_from_name)
    GETFUNADDR(il2cpp_class_get_fields)
    GETFUNADDR(il2cpp_class_get_flags)
    GETFUNADDR(il2cpp_class_get_image)
    GETFUNADDR(il2cpp_class_get_interfaces)
    GETFUNADDR(il2cpp_class_get_method_from_name)
    GETFUNADDR(il2cpp_class_get_methods)
    GETFUNADDR(il2cpp_class_get_name)
    GETFUNADDR(il2cpp_class_get_namespace)
    GETFUNADDR(il2cpp_class_get_nested_types)
    GETFUNADDR(il2cpp_class_get_parent)
    GETFUNADDR(il2cpp_class_get_properties)
    GETFUNADDR(il2cpp_class_get_property_from_name)
    GETFUNADDR(il2cpp_class_get_rank)
    GETFUNADDR(il2cpp_class_get_type)
    GETFUNADDR(il2cpp_class_get_type_token)
    GETFUNADDR(il2cpp_class_has_attribute)
    GETFUNADDR(il2cpp_class_has_parent)
    GETFUNADDR(il2cpp_class_has_references)
    GETFUNADDR(il2cpp_class_instance_size)
    GETFUNADDR(il2cpp_class_is_abstract)
    GETFUNADDR(il2cpp_class_is_assignable_from)
    GETFUNADDR(il2cpp_class_is_blittable)
    GETFUNADDR(il2cpp_class_is_enum)
    GETFUNADDR(il2cpp_class_is_generic)
    GETFUNADDR(il2cpp_class_is_inflated)
    GETFUNADDR(il2cpp_class_is_interface)
    GETFUNADDR(il2cpp_class_is_subclass_of)
    GETFUNADDR(il2cpp_class_num_fields)
    GETFUNADDR(il2cpp_class_value_size)
    GETFUNADDR(il2cpp_current_thread_get_frame_at)
    GETFUNADDR(il2cpp_current_thread_get_stack_depth)
    GETFUNADDR(il2cpp_current_thread_get_top_frame)
    GETFUNADDR(il2cpp_current_thread_walk_frame_stack)
    GETFUNADDR(il2cpp_custom_attrs_construct)
    GETFUNADDR(il2cpp_custom_attrs_free)
    GETFUNADDR(il2cpp_custom_attrs_from_class)
    GETFUNADDR(il2cpp_custom_attrs_from_method)
    GETFUNADDR(il2cpp_custom_attrs_get_attr)
    GETFUNADDR(il2cpp_custom_attrs_has_attr)
    GETFUNADDR(il2cpp_debugger_set_agent_options)
    GETFUNADDR(il2cpp_domain_assembly_open)
    GETFUNADDR(il2cpp_domain_get_assemblies)
    GETFUNADDR(il2cpp_exception_from_name_msg)
    GETFUNADDR(il2cpp_field_get_flags)
    GETFUNADDR(il2cpp_field_get_name)
    GETFUNADDR(il2cpp_field_get_offset)
    GETFUNADDR(il2cpp_field_get_parent)
    GETFUNADDR(il2cpp_field_get_type)
    GETFUNADDR(il2cpp_field_get_value)
    GETFUNADDR(il2cpp_field_get_value_object)
    GETFUNADDR(il2cpp_field_has_attribute)
    GETFUNADDR(il2cpp_field_set_value)
    GETFUNADDR(il2cpp_field_set_value_object)
    GETFUNADDR(il2cpp_field_static_get_value)
    GETFUNADDR(il2cpp_field_static_set_value)
    GETFUNADDR(il2cpp_format_exception)
    GETFUNADDR(il2cpp_format_stack_trace)
    GETFUNADDR(il2cpp_free)
    GETFUNADDR(il2cpp_free_captured_memory_snapshot)
    GETFUNADDR(il2cpp_gc_collect)
    GETFUNADDR(il2cpp_gc_collect_a_little)
    GETFUNADDR(il2cpp_gc_disable)
    GETFUNADDR(il2cpp_gc_enable)
    GETFUNADDR(il2cpp_gc_get_heap_size)
    GETFUNADDR(il2cpp_gc_get_used_size)
    GETFUNADDR(il2cpp_gc_is_disabled)
    GETFUNADDR(il2cpp_gchandle_free)
    GETFUNADDR(il2cpp_gchandle_get_target)
    GETFUNADDR(il2cpp_gchandle_new)
    GETFUNADDR(il2cpp_gchandle_new_weakref)
    GETFUNADDR(il2cpp_get_corlib)
    GETFUNADDR(il2cpp_get_exception_argument_null)
    GETFUNADDR(il2cpp_image_get_assembly)
    GETFUNADDR(il2cpp_image_get_class)
    GETFUNADDR(il2cpp_image_get_class_count)
    GETFUNADDR(il2cpp_image_get_entry_point)
    GETFUNADDR(il2cpp_image_get_filename)
    GETFUNADDR(il2cpp_image_get_name)
    GETFUNADDR(il2cpp_init)
    GETFUNADDR(il2cpp_init_utf16)
    GETFUNADDR(il2cpp_is_debugger_attached)
    GETFUNADDR(il2cpp_is_vm_thread)
    GETFUNADDR(il2cpp_method_get_class)
    GETFUNADDR(il2cpp_method_get_declaring_type)
    GETFUNADDR(il2cpp_method_get_flags)
    GETFUNADDR(il2cpp_method_get_from_reflection)
    GETFUNADDR(il2cpp_method_get_name)
    GETFUNADDR(il2cpp_method_get_object)
    GETFUNADDR(il2cpp_method_get_param)
    GETFUNADDR(il2cpp_method_get_param_count)
    GETFUNADDR(il2cpp_method_get_param_name)
    GETFUNADDR(il2cpp_method_get_return_type)
    GETFUNADDR(il2cpp_method_get_token)
    GETFUNADDR(il2cpp_method_has_attribute)
    GETFUNADDR(il2cpp_method_is_generic)
    GETFUNADDR(il2cpp_method_is_inflated)
    GETFUNADDR(il2cpp_method_is_instance)
    GETFUNADDR(il2cpp_monitor_pulse)
    GETFUNADDR(il2cpp_monitor_pulse_all)
    GETFUNADDR(il2cpp_monitor_try_enter)
    GETFUNADDR(il2cpp_monitor_try_wait)
    GETFUNADDR(il2cpp_monitor_wait)
    GETFUNADDR(il2cpp_object_get_class)
    GETFUNADDR(il2cpp_object_get_size)
    GETFUNADDR(il2cpp_object_get_virtual_method)
    GETFUNADDR(il2cpp_object_new)
    GETFUNADDR(il2cpp_profiler_install)
    GETFUNADDR(il2cpp_profiler_install_allocation)
    GETFUNADDR(il2cpp_profiler_install_enter_leave)
    GETFUNADDR(il2cpp_profiler_install_fileio)
    GETFUNADDR(il2cpp_profiler_install_gc)
    GETFUNADDR(il2cpp_profiler_install_thread)
    GETFUNADDR(il2cpp_profiler_set_events)
    GETFUNADDR(il2cpp_property_get_flags)
    GETFUNADDR(il2cpp_property_get_get_method)
    GETFUNADDR(il2cpp_property_get_name)
    GETFUNADDR(il2cpp_property_get_parent)
    GETFUNADDR(il2cpp_property_get_set_method)
    GETFUNADDR(il2cpp_raise_exception)
    GETFUNADDR(il2cpp_register_log_callback)
    GETFUNADDR(il2cpp_resolve_icall)
    GETFUNADDR(il2cpp_runtime_class_init)
    GETFUNADDR(il2cpp_runtime_invoke_convert_args)
    GETFUNADDR(il2cpp_runtime_object_init)
    GETFUNADDR(il2cpp_runtime_object_init_exception)
    GETFUNADDR(il2cpp_runtime_unhandled_exception_policy_set)
    GETFUNADDR(il2cpp_set_commandline_arguments)
    GETFUNADDR(il2cpp_set_commandline_arguments_utf16)
    GETFUNADDR(il2cpp_set_config)
    GETFUNADDR(il2cpp_set_config_dir)
    GETFUNADDR(il2cpp_set_config_utf16)
    GETFUNADDR(il2cpp_set_data_dir)
    GETFUNADDR(il2cpp_set_find_plugin_callback)
    GETFUNADDR(il2cpp_set_memory_callbacks)
    GETFUNADDR(il2cpp_set_temp_dir)
    GETFUNADDR(il2cpp_shutdown)
    GETFUNADDR(il2cpp_stats_dump_to_file)
    GETFUNADDR(il2cpp_stats_get_value)
    GETFUNADDR(il2cpp_string_chars)
    GETFUNADDR(il2cpp_string_intern)
    GETFUNADDR(il2cpp_string_is_interned)
    GETFUNADDR(il2cpp_string_length)
    GETFUNADDR(il2cpp_string_new)
    GETFUNADDR(il2cpp_string_new_len)
    GETFUNADDR(il2cpp_string_new_utf16)
    GETFUNADDR(il2cpp_string_new_wrapper)
    GETFUNADDR(il2cpp_thread_attach)
    GETFUNADDR(il2cpp_thread_current)
    GETFUNADDR(il2cpp_thread_detach)
    GETFUNADDR(il2cpp_thread_get_all_attached_threads)
    GETFUNADDR(il2cpp_thread_get_frame_at)
    GETFUNADDR(il2cpp_thread_get_stack_depth)
    GETFUNADDR(il2cpp_thread_get_top_frame)
    GETFUNADDR(il2cpp_thread_walk_frame_stack)
    GETFUNADDR(il2cpp_type_equals)
    GETFUNADDR(il2cpp_type_get_assembly_qualified_name)
    GETFUNADDR(il2cpp_type_get_attrs)
    GETFUNADDR(il2cpp_type_get_class_or_element_class)
    GETFUNADDR(il2cpp_type_get_name)
    GETFUNADDR(il2cpp_type_get_object)
    GETFUNADDR(il2cpp_type_get_type)
    GETFUNADDR(il2cpp_type_is_byref)
    GETFUNADDR(il2cpp_unhandled_exception)
    GETFUNADDR(il2cpp_unity_install_unitytls_interface)
    GETFUNADDR(il2cpp_unity_liveness_calculation_begin)
    GETFUNADDR(il2cpp_unity_liveness_calculation_end)
    GETFUNADDR(il2cpp_unity_liveness_calculation_from_root)
    GETFUNADDR(il2cpp_unity_liveness_calculation_from_statics)
    GETFUNADDR(il2cpp_value_box)
}


JNIEXPORT void JNICALL Java_com_ly_update_HotFixPlugin_Init(JNIEnv *env,
                                                            jclass jcls,
                                                            jstring jIl2cppPath,
                                                            jstring jmetaPath)
{
    const char* pIl2cppLib = env->GetStringUTFChars(jIl2cppPath, nullptr);
    const char* pMetaPath = nullptr;
    if(jmetaPath != NULL)
    {
        pMetaPath = env->GetStringUTFChars(jmetaPath, nullptr);
    }
    LOGD("Init:%s", pIl2cppLib);
    InitUpdate(pIl2cppLib, pMetaPath);
    env->ReleaseStringUTFChars(jIl2cppPath, pIl2cppLib);
    if(jmetaPath != NULL)
    {
        env->ReleaseStringUTFChars(jmetaPath, pMetaPath);
    }
}
//int g_init = 0;
void __attribute__ ((constructor)) so_init()
{
    //g_init++;
    LOGD("so_init:");
}
enum CPU_ABI
{
    ARM = 0,
    ARM64,
    X86,
    X64
};

JNIEXPORT jint JNICALL Java_com_ly_update_HotFixPlugin_GetRunningCpuType
        (JNIEnv *, jclass)
{
#ifdef __arm__
    return CPU_ABI::ARM;
#elif defined(__aarch64__)
    return CPU_ABI::ARM64;
#elif defined(__i386__)
    return CPU_ABI::X86;
#elif defined(__x86_64__)
    return CPU_ABI::X64;
#else
#error Not Support ABI
#endif

    }
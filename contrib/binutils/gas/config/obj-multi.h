begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hi */
end_comment

begin_include
include|#
directive|include
file|"emul.h"
end_include

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|(this_format->flavor)
end_define

begin_define
define|#
directive|define
name|obj_frob_symbol
parameter_list|(
name|S
parameter_list|,
name|P
parameter_list|)
value|(this_format->frob_symbol)(S,&(P))
end_define

begin_define
define|#
directive|define
name|obj_frob_file
value|(this_format->frob_file)
end_define

begin_define
define|#
directive|define
name|obj_frob_file_after_relocs
value|(this_format->frob_file_after_relocs)
end_define

begin_define
define|#
directive|define
name|obj_ecoff_set_ext
value|(this_format->ecoff_set_ext)
end_define

begin_define
define|#
directive|define
name|obj_pop_insert
value|(this_format->pop_insert)
end_define

begin_define
define|#
directive|define
name|obj_read_begin_hook
parameter_list|()
value|(this_format->read_begin_hook?this_format->read_begin_hook():(void)0)
end_define

begin_define
define|#
directive|define
name|obj_symbol_new_hook
value|(this_format->symbol_new_hook)
end_define

begin_define
define|#
directive|define
name|obj_sec_sym_ok_for_reloc
value|(this_format->sec_sym_ok_for_reloc)
end_define

begin_define
define|#
directive|define
name|S_GET_SIZE
value|(this_format->s_get_size)
end_define

begin_define
define|#
directive|define
name|S_SET_SIZE
value|(this_format->s_set_size)
end_define

begin_define
define|#
directive|define
name|S_GET_ALIGN
value|(this_format->s_get_align)
end_define

begin_define
define|#
directive|define
name|S_SET_ALIGN
value|(this_format->s_set_align)
end_define

begin_define
define|#
directive|define
name|obj_copy_symbol_attributes
value|(this_format->copy_symbol_attributes)
end_define

begin_define
define|#
directive|define
name|OBJ_PROCESS_STAB
value|(this_format->process_stab)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBJ_MAYBE_ECOFF
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|OBJ_MAYBE_ELF
argument_list|)
operator|&&
name|defined
argument_list|(
name|TC_MIPS
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ECOFF_DEBUGGING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIXME: What's the story here?  Why do we have to define    OBJ_SYMFIELD_TYPE both here and in obj-elf.h?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_MAYBE_ELF
end_ifdef

begin_struct
struct|struct
name|elf_obj_sy
block|{
name|expressionS
modifier|*
name|size
decl_stmt|;
name|char
modifier|*
name|versioned_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OBJ_SYMFIELD_TYPE
value|struct elf_obj_sy
end_define

begin_define
define|#
directive|define
name|ELF_TARGET_SYMBOL_FIELDS
value|int local:1;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELF_TARGET_SYMBOL_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ECOFF_DEBUGGING
end_ifdef

begin_struct_decl
struct_decl|struct
name|efdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|localsym
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ECOFF_DEBUG_TARGET_SYMBOL_FIELDS
value|struct efdr *ecoff_file; struct localsym *ecoff_symbol; valueT ecoff_extern_size;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ECOFF_DEBUG_TARGET_SYMBOL_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_SYMBOL_FIELDS
define|\
value|ELF_TARGET_SYMBOL_FIELDS \ 	ECOFF_DEBUG_TARGET_SYMBOL_FIELDS
end_define

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003-2006 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UWX_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|__UWX_INCLUDED
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__EXTERN_C
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__EXTERN_C
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UWX_VERSION
value|3
end_define

begin_comment
comment|/* Version id for callback interfaces */
end_comment

begin_comment
comment|/* Unwind environment structure (opaque) */
end_comment

begin_struct_decl
struct_decl|struct
name|uwx_env
struct_decl|;
end_struct_decl

begin_comment
comment|/* Symbol Cache for uwx_find_symbol (opaque) */
end_comment

begin_struct_decl
struct_decl|struct
name|uwx_symbol_cache
struct_decl|;
end_struct_decl

begin_comment
comment|/* Allocate and free callbacks */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|alloc_cb
function_decl|)
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|free_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_register_alloc_cb
parameter_list|(
name|alloc_cb
name|alloc
parameter_list|,
name|free_cb
name|free
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate and initialize an unwind environment */
end_comment

begin_function_decl
name|__EXTERN_C
name|struct
name|uwx_env
modifier|*
name|uwx_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free an unwind environment */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_free
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Put unwind express into cross-process mode */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_set_remote
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|int
name|is_big_endian_target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Put unwind express into reduced-context mode (no floating-point regs) */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_set_nofr
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy-in callback */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|copyin_cb
function_decl|)
parameter_list|(
name|int
name|request
parameter_list|,
comment|/* request code (see below) */
name|char
modifier|*
name|loc
parameter_list|,
comment|/* local (destination) address */
name|uint64_t
name|rem
parameter_list|,
comment|/* remote (source) address */
name|int
name|len
parameter_list|,
comment|/* number of bytes to copy */
name|intptr_t
name|tok
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* callback token */
end_comment

begin_comment
comment|/* Lookup IP callback */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|lookupip_cb
function_decl|)
parameter_list|(
name|int
name|request
parameter_list|,
comment|/* request code (see below) */
name|uint64_t
name|ip
parameter_list|,
comment|/* IP of current frame */
name|intptr_t
name|tok
parameter_list|,
comment|/* callback token */
name|uint64_t
modifier|*
modifier|*
name|vecp
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* parameter vector (in/out) */
end_comment

begin_comment
comment|/* Register copy-in and lookup IP callbacks */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_register_callbacks
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|intptr_t
name|tok
parameter_list|,
comment|/* callback token */
name|copyin_cb
name|copyin
parameter_list|,
comment|/* copy-in callback */
name|lookupip_cb
name|lookupip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup IP callback */
end_comment

begin_comment
comment|/* Initialize a context with the basic info needed to start an unwind */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_init_context
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|uint64_t
name|ip
parameter_list|,
comment|/* IP (instruction pointer) */
name|uint64_t
name|sp
parameter_list|,
comment|/* SP (stack pointer) */
name|uint64_t
name|bsp
parameter_list|,
comment|/* BSP (backing store pointer) */
name|uint64_t
name|cfm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CFM (current frame marker) */
end_comment

begin_comment
comment|/* Set the value of a specific register in the current context (non fp) */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_set_reg
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|int
name|regid
parameter_list|,
comment|/* register id (see below) */
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* register value */
end_comment

begin_comment
comment|/* Set the value of a floating-point register in the current context */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_set_fr
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|int
name|regid
parameter_list|,
comment|/* register id (see below) */
name|uint64_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* register value (ptr to 16 bytes) */
end_comment

begin_comment
comment|/*   (memory spill format) */
end_comment

begin_comment
comment|/* Initialize the unwind history */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_init_history
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Step one frame */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_step
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get module name and text base, if available, for current frame */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_get_module_info
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|char
modifier|*
modifier|*
name|modp
parameter_list|,
comment|/* load module name (out)  */
name|uint64_t
modifier|*
name|text_base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* base address of text segment (out)  */
end_comment

begin_comment
comment|/* Get function start address for current frame */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_get_funcstart
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|uint64_t
modifier|*
name|funcstart
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* function start address (out)  */
end_comment

begin_comment
comment|/* Get symbol information, if available, for current frame */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_get_sym_info
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|char
modifier|*
modifier|*
name|modp
parameter_list|,
comment|/* load module name (out)  */
name|char
modifier|*
modifier|*
name|symp
parameter_list|,
comment|/* function name (out)  */
name|uint64_t
modifier|*
name|offsetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* offset from start of function (out)  */
end_comment

begin_comment
comment|/* Get symbol information, given module name and IP */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_find_symbol
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|struct
name|uwx_symbol_cache
modifier|*
modifier|*
name|cachep
parameter_list|,
comment|/* ptr to symbol cache ptr (in/out) */
name|char
modifier|*
name|mod
parameter_list|,
comment|/* load module name */
name|uint64_t
name|relip
parameter_list|,
comment|/* IP, relative to text segment  */
name|char
modifier|*
modifier|*
name|symp
parameter_list|,
comment|/* function name (out) */
name|uint64_t
modifier|*
name|offsetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* offset from start of function (out) */
end_comment

begin_comment
comment|/* Release memory used by symbol cache */
end_comment

begin_function_decl
name|__EXTERN_C
name|void
name|uwx_release_symbol_cache
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|struct
name|uwx_symbol_cache
modifier|*
name|symbol_cache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* symbol cache ptr */
end_comment

begin_comment
comment|/* Get the value of a register from the current context */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_get_reg
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|int
name|regid
parameter_list|,
comment|/* register id (see below) */
name|uint64_t
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* register value (out) */
end_comment

begin_comment
comment|/* Get the NaT bit of a GR from the current context */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_get_nat
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|int
name|regid
parameter_list|,
comment|/* register id (see below) */
name|int
modifier|*
name|natp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NaT value (out: 0 or 1) */
end_comment

begin_comment
comment|/* Get the spill location for a register in the current context */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_get_spill_loc
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
comment|/* unwind environment */
name|int
name|regid
parameter_list|,
comment|/* register id (see below) */
name|uint64_t
modifier|*
name|dispp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* disposition code (see below) (out) */
end_comment

begin_comment
comment|/* Get the ABI context code (if uwx_step returned UWX_ABI_FRAME) */
end_comment

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_get_abi_context_code
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Increment/Decrement the bsp by a number of slots */
end_comment

begin_comment
comment|/* (accounts for NaT collections) */
end_comment

begin_function_decl
name|__EXTERN_C
name|uint64_t
name|uwx_add_to_bsp
parameter_list|(
name|uint64_t
name|bsp
parameter_list|,
name|int
name|nslots
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return status codes for uwx_ APIs */
end_comment

begin_define
define|#
directive|define
name|UWX_OK
value|0
end_define

begin_define
define|#
directive|define
name|UWX_BOTTOM
value|1
end_define

begin_comment
comment|/* Hit bottom of stack */
end_comment

begin_define
define|#
directive|define
name|UWX_ABI_FRAME
value|2
end_define

begin_comment
comment|/* Hit ABI-dependent frame */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_NOENV
value|(-1)
end_define

begin_comment
comment|/* No uwx_env allocated */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_IPNOTFOUND
value|(-2)
end_define

begin_comment
comment|/* Lookup IP c/b returned NOTFOUND */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_LOOKUPERR
value|(-3)
end_define

begin_comment
comment|/* Lookup IP c/b returned ERR */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_BADKEY
value|(-4)
end_define

begin_comment
comment|/* Bad result vector key */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_COPYIN_UTBL
value|(-5)
end_define

begin_comment
comment|/* Error reading unwind table */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_COPYIN_UINFO
value|(-6)
end_define

begin_comment
comment|/* Error reading unwind info */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_COPYIN_MSTK
value|(-7)
end_define

begin_comment
comment|/* Error reading memory stack */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_COPYIN_RSTK
value|(-8)
end_define

begin_comment
comment|/* Error reading register stack */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_COPYIN_REG
value|(-9)
end_define

begin_comment
comment|/* Error reading context register */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_NOUENTRY
value|(-10)
end_define

begin_comment
comment|/* No unwind table entry for ip */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_NOUDESC
value|(-11)
end_define

begin_comment
comment|/* No unwind descriptor covers ip */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_BADUDESC
value|(-12)
end_define

begin_comment
comment|/* Bad unwind descriptor */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_NOMEM
value|(-13)
end_define

begin_comment
comment|/* Out of memory */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_PROLOG_UF
value|(-14)
end_define

begin_comment
comment|/* Prologue underflow */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_UNDEFLABEL
value|(-15)
end_define

begin_comment
comment|/* Undefined label in copy_state */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_BADREGID
value|(-16)
end_define

begin_comment
comment|/* Bad register identifier */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_CANTUNWIND
value|(-17)
end_define

begin_comment
comment|/* Can't unwind */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_NOCALLBACKS
value|(-18)
end_define

begin_comment
comment|/* No callbacks registered */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_NOCONTEXT
value|(-19)
end_define

begin_comment
comment|/* Context not initialized */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_UCACCESS
value|(-20)
end_define

begin_comment
comment|/* Failure in libuca */
end_comment

begin_define
define|#
directive|define
name|UWX_ERR_NOSYM
value|(-21)
end_define

begin_comment
comment|/* Symbol not found */
end_comment

begin_comment
comment|/* Request codes for copyin callback */
end_comment

begin_define
define|#
directive|define
name|UWX_COPYIN_UINFO
value|1
end_define

begin_comment
comment|/* Reading unwind info */
end_comment

begin_define
define|#
directive|define
name|UWX_COPYIN_MSTACK
value|2
end_define

begin_comment
comment|/* Reading memory stack */
end_comment

begin_define
define|#
directive|define
name|UWX_COPYIN_RSTACK
value|3
end_define

begin_comment
comment|/* Reading RSE backing store */
end_comment

begin_define
define|#
directive|define
name|UWX_COPYIN_REG
value|4
end_define

begin_comment
comment|/* Reading initial register state */
end_comment

begin_comment
comment|/* Request codes for lookup IP callback */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_LOOKUP
value|1
end_define

begin_comment
comment|/* Lookup IP */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_FREE
value|2
end_define

begin_comment
comment|/* Free result vector */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_SYMBOLS
value|3
end_define

begin_comment
comment|/* Lookup symbolic information */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_MODULE
value|4
end_define

begin_comment
comment|/* Get module name */
end_comment

begin_comment
comment|/* Return status codes for lookup IP callback */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_NOTFOUND
value|0
end_define

begin_comment
comment|/* IP not found */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_ERR
value|1
end_define

begin_comment
comment|/* Other error */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_UTABLE
value|2
end_define

begin_comment
comment|/* Returned ref to unwind table */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_FDESC
value|3
end_define

begin_comment
comment|/* Returned frame description */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_SYMINFO
value|4
end_define

begin_comment
comment|/* Returned symbolic information */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_REMAP
value|5
end_define

begin_comment
comment|/* Returned remapped IP */
end_comment

begin_define
define|#
directive|define
name|UWX_LKUP_UINFO
value|6
end_define

begin_comment
comment|/* Returned unw info block ptr */
end_comment

begin_comment
comment|/* The lookup IP callback receives a parameter vector, and returns */
end_comment

begin_comment
comment|/* one on success. This vector is a series of key/value pairs; each */
end_comment

begin_comment
comment|/* even-numbered slot is a key, and each odd-numbered slot is a */
end_comment

begin_comment
comment|/* corresponding value. The vector is terminated by a pair whose */
end_comment

begin_comment
comment|/* key is 0. */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_END
value|0
end_define

begin_comment
comment|/* End of vector */
end_comment

begin_comment
comment|/* Keys passed to lookup IP callback */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_PREDS
value|1
end_define

begin_comment
comment|/* Predicate registers */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_VERSION
value|2
end_define

begin_comment
comment|/* Version id of unwind engine */
end_comment

begin_comment
comment|/* UWX_KEY_FUNCSTART (below) may also be passed with the UWX_LKUP_SYMINFO */
end_comment

begin_comment
comment|/* request. */
end_comment

begin_comment
comment|/* Keys returned with UWX_LKUP_UTABLE */
end_comment

begin_comment
comment|/* These key/value pairs describe the unwind table corresponding */
end_comment

begin_comment
comment|/* to the load module in which the current IP resides. */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_TBASE
value|1
end_define

begin_comment
comment|/* Base address of text seg */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_UFLAGS
value|2
end_define

begin_comment
comment|/* Unwind flags (optional) */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_USTART
value|3
end_define

begin_comment
comment|/* Base of unwind tbl */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_UEND
value|4
end_define

begin_comment
comment|/* End of unwind tbl */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_GP
value|7
end_define

begin_comment
comment|/* GP value for module */
end_comment

begin_comment
comment|/* Keys returned with UWX_LKUP_FDESC */
end_comment

begin_comment
comment|/* These key/value pairs describe the state of the frame at the */
end_comment

begin_comment
comment|/* given IP. They are typically used for dynamically-generated code. */
end_comment

begin_comment
comment|/* If UWX_KEY_CONTEXT is returned, it must be the only key returned. */
end_comment

begin_comment
comment|/* Use UWX_KEY_GP for the module's gp value. */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_FSIZE
value|1
end_define

begin_comment
comment|/* Frame size */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_SPILL
parameter_list|(
name|reg_id
parameter_list|)
value|(2 | ((reg_id)<< 4))
end_define

begin_comment
comment|/* Reg spilled */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_CONTEXT
value|3
end_define

begin_comment
comment|/* ABI-dep. context */
end_comment

begin_comment
comment|/* Keys returned with UWX_LKUP_REMAP */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_NEWIP
value|5
end_define

begin_comment
comment|/* Remapped IP */
end_comment

begin_comment
comment|/* Keys returned with UWX_LKUP_UINFO */
end_comment

begin_comment
comment|/* Use UWX_KEY_GP for the module's gp value. */
end_comment

begin_comment
comment|/* Use UWX_KEY_FUNCSTART for the start address of the function */
end_comment

begin_comment
comment|/* Use UWX_KEY_UFLAGS for the unwind flags (optional) */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_UINFO
value|6
end_define

begin_comment
comment|/* Address of unwind info block */
end_comment

begin_comment
comment|/* Keys returned with UWX_LKUP_SYMINFO */
end_comment

begin_comment
comment|/* These keys may be returned with UWX_LKUP_FDESC or UWX_LKUP_UINFO, */
end_comment

begin_comment
comment|/* if the information is cheap to obtain. */
end_comment

begin_comment
comment|/* Use UWX_KEY_TBASE for the base of the text segment */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_MODULE
value|17
end_define

begin_comment
comment|/* Name of load module */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_FUNC
value|18
end_define

begin_comment
comment|/* Name of function */
end_comment

begin_define
define|#
directive|define
name|UWX_KEY_FUNCSTART
value|19
end_define

begin_comment
comment|/* Address of start of function */
end_comment

begin_comment
comment|/* Register identifiers */
end_comment

begin_comment
comment|/* For use in UWX_LKUP_FDESC result vectors and context access APIs. */
end_comment

begin_comment
comment|/* "no spill info": These regs aren't spilled directly, so */
end_comment

begin_comment
comment|/*    result vectors must not describe these registers. */
end_comment

begin_comment
comment|/*    The result vector must describe the related register or */
end_comment

begin_comment
comment|/*    pseudo register instead (ip:rp, sp:psp, bsp/cfm:pfs). */
end_comment

begin_comment
comment|/* "pseudo register": Not a machine register, but treated as */
end_comment

begin_comment
comment|/*    one for unwind purposes. */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_IP
value|0
end_define

begin_comment
comment|/* ip (no spill info) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_SP
value|1
end_define

begin_comment
comment|/* sp (no spill info) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_BSP
value|2
end_define

begin_comment
comment|/* ar.bsp (no spill info) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_CFM
value|3
end_define

begin_comment
comment|/* cfm (no spill info) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_RP
value|4
end_define

begin_comment
comment|/* rp (pseudo-register) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_PSP
value|5
end_define

begin_comment
comment|/* psp (pseudo-register) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_PFS
value|6
end_define

begin_comment
comment|/* pfs (pseudo-register) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_PREDS
value|7
end_define

begin_comment
comment|/* p0 - p63 */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_PRIUNAT
value|8
end_define

begin_comment
comment|/* primary unat (pseudo-register) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_AR_BSPSTORE
value|9
end_define

begin_comment
comment|/* ar.bspstore */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_AR_RNAT
value|10
end_define

begin_comment
comment|/* ar.rnat */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_AR_UNAT
value|11
end_define

begin_comment
comment|/* ar.unat */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_AR_FPSR
value|12
end_define

begin_comment
comment|/* ar.fpsr */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_AR_LC
value|13
end_define

begin_comment
comment|/* ar.lc */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_AR_PFS
value|14
end_define

begin_comment
comment|/* ar.pfs */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_GP
value|15
end_define

begin_comment
comment|/* gp (pseudo-register) */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_GR
parameter_list|(
name|gr
parameter_list|)
value|(0x100 | (gr))
end_define

begin_define
define|#
directive|define
name|UWX_REG_FR
parameter_list|(
name|fr
parameter_list|)
value|(0x200 | (fr))
end_define

begin_define
define|#
directive|define
name|UWX_REG_BR
parameter_list|(
name|br
parameter_list|)
value|(0x300 | (br))
end_define

begin_comment
comment|/* for backwards compatibility with previous releases... */
end_comment

begin_define
define|#
directive|define
name|UWX_REG_BSPSTORE
value|UWX_REG_AR_BSPSTORE
end_define

begin_define
define|#
directive|define
name|UWX_REG_RNAT
value|UWX_REG_AR_RNAT
end_define

begin_define
define|#
directive|define
name|UWX_REG_UNAT
value|UWX_REG_AR_UNAT
end_define

begin_define
define|#
directive|define
name|UWX_REG_FPSR
value|UWX_REG_AR_FPSR
end_define

begin_define
define|#
directive|define
name|UWX_REG_LC
value|UWX_REG_AR_LC
end_define

begin_comment
comment|/* Values corresponding to UWX_KEY_SPILL keys indicate the disposition */
end_comment

begin_comment
comment|/* of the spilled register -- either in the memory stack or in another */
end_comment

begin_comment
comment|/* register. The PSP register may also have a disposition of "SPPLUS", */
end_comment

begin_comment
comment|/* indicating that its value is SP plus a fixed constant. */
end_comment

begin_define
define|#
directive|define
name|UWX_DISP_NONE
value|0
end_define

begin_comment
comment|/* Not spilled */
end_comment

begin_define
define|#
directive|define
name|UWX_DISP_SPPLUS
parameter_list|(
name|k
parameter_list|)
value|(1 | (k))
end_define

begin_comment
comment|/* PSP = SP+constant */
end_comment

begin_define
define|#
directive|define
name|UWX_DISP_SPREL
parameter_list|(
name|disp
parameter_list|)
value|(2 | (disp))
end_define

begin_comment
comment|/* Spilled at [SP+disp] */
end_comment

begin_define
define|#
directive|define
name|UWX_DISP_PSPREL
parameter_list|(
name|disp
parameter_list|)
value|(3 | (disp))
end_define

begin_comment
comment|/* Spilled at [PSP+16-disp] */
end_comment

begin_define
define|#
directive|define
name|UWX_DISP_REG
parameter_list|(
name|reg
parameter_list|)
value|(4 | ((reg)<< 4))
end_define

begin_comment
comment|/* Saved to another reg. */
end_comment

begin_comment
comment|/* The uwx_get_spill_loc() routine returns a spill location for a */
end_comment

begin_comment
comment|/* given register in the current context. It will return a disposition */
end_comment

begin_comment
comment|/* code of UWX_DISP_NONE, UWX_DISP_REG(reg), or one of the following */
end_comment

begin_comment
comment|/* to indicate that the spilled value can be found in the memory */
end_comment

begin_comment
comment|/* stack or the register stack backing store. */
end_comment

begin_define
define|#
directive|define
name|UWX_DISP_MSTK
parameter_list|(
name|addr
parameter_list|)
value|(5 | (addr))
end_define

begin_comment
comment|/* Spilled in mem. stack */
end_comment

begin_define
define|#
directive|define
name|UWX_DISP_RSTK
parameter_list|(
name|addr
parameter_list|)
value|(6 | (addr))
end_define

begin_comment
comment|/* Spilled in reg. stack */
end_comment

begin_comment
comment|/* Extract the disposition code, offset, address, or register id */
end_comment

begin_comment
comment|/* from a disposition returned from uwx_get_spill_loc(). */
end_comment

begin_comment
comment|/* Compare the extracted disp code against UWX_DISP_REG(0), etc. */
end_comment

begin_define
define|#
directive|define
name|UWX_GET_DISP_CODE
parameter_list|(
name|disp
parameter_list|)
value|((int)(disp)& 0x07)
end_define

begin_define
define|#
directive|define
name|UWX_GET_DISP_OFFSET
parameter_list|(
name|disp
parameter_list|)
value|((disp)& ~(uint64_t)0x07)
end_define

begin_define
define|#
directive|define
name|UWX_GET_DISP_ADDR
parameter_list|(
name|disp
parameter_list|)
value|((disp)& ~(uint64_t)0x07)
end_define

begin_define
define|#
directive|define
name|UWX_GET_DISP_REGID
parameter_list|(
name|disp
parameter_list|)
value|((int)(disp)>> 4)
end_define

begin_undef
undef|#
directive|undef
name|__EXTERN_C
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_decl_stmt
name|class
name|UnwindExpress
block|{
name|public
label|:
name|UnwindExpress
argument_list|()
block|{
name|env
operator|=
name|uwx_init
argument_list|()
expr_stmt|;
block|}
operator|~
name|UnwindExpress
argument_list|()
block|{
if|if
condition|(
name|env
operator|!=
literal|0
condition|)
name|uwx_free
argument_list|(
name|env
argument_list|)
expr_stmt|;
name|env
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|int
name|init_context
parameter_list|(
name|uint64_t
name|ip
parameter_list|,
name|uint64_t
name|sp
parameter_list|,
name|uint64_t
name|bsp
parameter_list|,
name|uint64_t
name|cfm
parameter_list|)
block|{
return|return
name|uwx_init_context
argument_list|(
name|env
argument_list|,
name|ip
argument_list|,
name|sp
argument_list|,
name|bsp
argument_list|,
name|cfm
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|init_history
parameter_list|()
block|{
return|return
name|uwx_init_history
argument_list|(
name|env
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|set_reg
parameter_list|(
name|int
name|regid
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
return|return
name|uwx_set_reg
argument_list|(
name|env
argument_list|,
name|regid
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|set_fr
parameter_list|(
name|int
name|regid
parameter_list|,
name|uint64_t
modifier|*
name|valp
parameter_list|)
block|{
return|return
name|uwx_set_fr
argument_list|(
name|env
argument_list|,
name|regid
argument_list|,
name|valp
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|step
parameter_list|()
block|{
return|return
name|uwx_step
argument_list|(
name|env
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|get_module_info
parameter_list|(
name|char
modifier|*
modifier|*
name|modp
parameter_list|,
name|uint64_t
modifier|*
name|text_base_p
parameter_list|)
block|{
return|return
name|uwx_get_module_info
argument_list|(
name|env
argument_list|,
name|modp
argument_list|,
name|text_base_p
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|get_funcstart
parameter_list|(
name|uint64_t
modifier|*
name|funcstart
parameter_list|)
block|{
return|return
name|uwx_get_funcstart
argument_list|(
name|env
argument_list|,
name|funcstart
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|get_sym_info
parameter_list|(
name|char
modifier|*
modifier|*
name|modp
parameter_list|,
name|char
modifier|*
modifier|*
name|symp
parameter_list|,
name|uint64_t
modifier|*
name|offsetp
parameter_list|)
block|{
return|return
name|uwx_get_sym_info
argument_list|(
name|env
argument_list|,
name|modp
argument_list|,
name|symp
argument_list|,
name|offsetp
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|find_symbol
parameter_list|(
name|struct
name|uwx_symbol_cache
modifier|*
modifier|*
name|cachep
parameter_list|,
name|char
modifier|*
name|mod
parameter_list|,
name|uint64_t
name|relip
parameter_list|,
name|char
modifier|*
modifier|*
name|symp
parameter_list|,
name|uint64_t
modifier|*
name|offsetp
parameter_list|)
block|{
return|return
name|uwx_find_symbol
argument_list|(
name|env
argument_list|,
name|cachep
argument_list|,
name|mod
argument_list|,
name|relip
argument_list|,
name|symp
argument_list|,
name|offsetp
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|release_symbol_cache
parameter_list|(
name|struct
name|uwx_symbol_cache
modifier|*
name|symbol_cache
parameter_list|)
block|{
name|uwx_release_symbol_cache
argument_list|(
name|env
argument_list|,
name|symbol_cache
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|get_reg
parameter_list|(
name|int
name|regid
parameter_list|,
name|uint64_t
modifier|*
name|valp
parameter_list|)
block|{
return|return
name|uwx_get_reg
argument_list|(
name|env
argument_list|,
name|regid
argument_list|,
name|valp
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|get_nat
parameter_list|(
name|int
name|regid
parameter_list|,
name|int
modifier|*
name|natp
parameter_list|)
block|{
return|return
name|uwx_get_nat
argument_list|(
name|env
argument_list|,
name|regid
argument_list|,
name|natp
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|get_spill_loc
parameter_list|(
name|int
name|regid
parameter_list|,
name|uint64_t
modifier|*
name|dispp
parameter_list|)
block|{
return|return
name|uwx_get_spill_loc
argument_list|(
name|env
argument_list|,
name|regid
argument_list|,
name|dispp
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|get_abi_context_code
parameter_list|()
block|{
return|return
name|uwx_get_abi_context_code
argument_list|(
name|env
argument_list|)
return|;
block|}
end_function

begin_function
name|struct
name|uwx_env
modifier|*
name|get_env
parameter_list|()
block|{
return|return
name|env
return|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|struct
name|uwx_env
modifier|*
name|env
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __UWX_INCLUDED */
end_comment

end_unit


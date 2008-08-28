begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: exc.h,v 1.23 2001/06/07 20:04:53 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm exception handling **  See libsm/exc.html for documentation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_EXC_H
end_ifndef

begin_define
define|#
directive|define
name|SM_EXC_H
end_define

begin_include
include|#
directive|include
file|<sm/setjmp.h>
end_include

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_include
include|#
directive|include
file|<sm/assert.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|sm_exc
name|SM_EXC_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sm_exc_type
name|SM_EXC_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|sm_val
name|SM_VAL_T
typedef|;
end_typedef

begin_comment
comment|/* **  Exception types */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|SmExcTypeMagic
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sm_exc_type
block|{
specifier|const
name|char
modifier|*
name|sm_magic
decl_stmt|;
specifier|const
name|char
modifier|*
name|etype_category
decl_stmt|;
specifier|const
name|char
modifier|*
name|etype_argformat
decl_stmt|;
name|void
argument_list|(
argument|*etype_print
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
operator|,
name|SM_FILE_T
operator|*
operator|)
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|etype_printcontext
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|SM_EXC_TYPE_T
name|SmEtypeOs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|SM_EXC_TYPE_T
name|SmEtypeErr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_etype_printf
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
name|_exc
operator|,
name|SM_FILE_T
operator|*
name|_stream
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Exception objects */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|SmExcMagic
index|[]
decl_stmt|;
end_decl_stmt

begin_union
union|union
name|sm_val
block|{
name|int
name|v_int
decl_stmt|;
name|long
name|v_long
decl_stmt|;
name|char
modifier|*
name|v_str
decl_stmt|;
name|SM_EXC_T
modifier|*
name|v_exc
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|sm_exc
block|{
specifier|const
name|char
modifier|*
name|sm_magic
decl_stmt|;
name|size_t
name|exc_refcount
decl_stmt|;
specifier|const
name|SM_EXC_TYPE_T
modifier|*
name|exc_type
decl_stmt|;
name|SM_VAL_T
modifier|*
name|exc_argv
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SM_EXC_INITIALIZER
parameter_list|(
name|type
parameter_list|,
name|argv
parameter_list|)
define|\
value|{ \ 		SmExcMagic, \ 		0, \ 		type, \ 		argv, \ 	}
end_define

begin_decl_stmt
specifier|extern
name|SM_EXC_T
modifier|*
name|sm_exc_new_x
name|__P
argument_list|(
operator|(
specifier|const
name|SM_EXC_TYPE_T
operator|*
name|_type
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_EXC_T
modifier|*
name|sm_exc_addref
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
name|_exc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_exc_free
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
name|_exc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sm_exc_match
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
name|_exc
operator|,
specifier|const
name|char
operator|*
name|_pattern
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_exc_write
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
name|_exc
operator|,
name|SM_FILE_T
operator|*
name|_stream
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_exc_print
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
name|_exc
operator|,
name|SM_FILE_T
operator|*
name|_stream
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern SM_DEAD(void sm_exc_raise_x __P(( 	SM_EXC_T *_exc
end_extern

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern SM_DEAD(void sm_exc_raisenew_x __P(( 	const SM_EXC_TYPE_T *_type
operator|,
extern|...
end_extern

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* **  Exception handling */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*SM_EXC_DEFAULT_HANDLER_T
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_EXC_T
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|sm_exc_newthread
name|__P
argument_list|(
operator|(
name|SM_EXC_DEFAULT_HANDLER_T
name|_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|sm_exc_handler
name|SM_EXC_HANDLER_T
typedef|;
end_typedef

begin_struct
struct|struct
name|sm_exc_handler
block|{
name|SM_EXC_T
modifier|*
name|eh_value
decl_stmt|;
name|SM_JMPBUF_T
name|eh_context
decl_stmt|;
name|SM_EXC_HANDLER_T
modifier|*
name|eh_parent
decl_stmt|;
name|int
name|eh_state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* values for eh_state */
end_comment

begin_enum
enum|enum
block|{
name|SM_EH_PUSHED
init|=
literal|2
block|,
name|SM_EH_POPPED
init|=
literal|0
block|,
name|SM_EH_HANDLED
init|=
literal|1
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|SM_EXC_HANDLER_T
modifier|*
name|SmExcHandler
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SM_TRY
value|{ SM_EXC_HANDLER_T _h; \ 			  do { \ 			    _h.eh_value = NULL; \ 			    _h.eh_parent = SmExcHandler; \ 			    _h.eh_state = SM_EH_PUSHED; \ 			    SmExcHandler =&_h; \ 			    if (sm_setjmp_nosig(_h.eh_context) == 0) {
end_define

begin_define
define|#
directive|define
name|SM_FINALLY
value|SM_ASSERT(SmExcHandler ==&_h); \ 			    } \ 			    if (sm_setjmp_nosig(_h.eh_context) == 0) {
end_define

begin_define
define|#
directive|define
name|SM_EXCEPT
parameter_list|(
name|e
parameter_list|,
name|pat
parameter_list|)
value|} \ 			    if (_h.eh_state == SM_EH_HANDLED) \ 			      break; \ 			    if (_h.eh_state == SM_EH_PUSHED) { \ 			      SM_ASSERT(SmExcHandler ==&_h); \ 			      SmExcHandler = _h.eh_parent; \ 			    } \ 			    _h.eh_state = sm_exc_match(_h.eh_value,pat) \ 			      ? SM_EH_HANDLED : SM_EH_POPPED; \ 			    if (_h.eh_state == SM_EH_HANDLED) { \ 			      SM_UNUSED(SM_EXC_T *e) = _h.eh_value;
end_define

begin_define
define|#
directive|define
name|SM_END_TRY
value|} \ 			  } while (0); \ 			  if (_h.eh_state == SM_EH_PUSHED) { \ 			    SM_ASSERT(SmExcHandler ==&_h); \ 			    SmExcHandler = _h.eh_parent; \ 			    if (_h.eh_value != NULL) \ 			      sm_exc_raise_x(_h.eh_value); \ 			  } else if (_h.eh_state == SM_EH_POPPED) { \ 			    if (_h.eh_value != NULL) \ 			      sm_exc_raise_x(_h.eh_value); \ 			  } else \ 			    sm_exc_free(_h.eh_value); \ 			}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_EXC_H */
end_comment

end_unit


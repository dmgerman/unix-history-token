begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ICONV_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ICONV_H_
end_define

begin_define
define|#
directive|define
name|ICONV_CSNMAXLEN
value|31
end_define

begin_comment
comment|/* maximum length of charset name */
end_comment

begin_define
define|#
directive|define
name|ICONV_CNVNMAXLEN
value|31
end_define

begin_comment
comment|/* maximum length of converter name */
end_comment

begin_define
define|#
directive|define
name|ICONV_CSMAXDATALEN
value|(2048+262144)
end_define

begin_comment
comment|/* maximum size of data associated with cs pair */
end_comment

begin_define
define|#
directive|define
name|XLAT16_ACCEPT_NULL_OUT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|XLAT16_ACCEPT_NULL_IN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|XLAT16_HAS_LOWER_CASE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|XLAT16_HAS_UPPER_CASE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|XLAT16_HAS_FROM_LOWER_CASE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|XLAT16_HAS_FROM_UPPER_CASE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|XLAT16_IS_3BYTE_CHR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|KICONV_LOWER
value|1
end_define

begin_comment
comment|/* tolower converted character */
end_comment

begin_define
define|#
directive|define
name|KICONV_UPPER
value|2
end_define

begin_comment
comment|/* toupper converted character */
end_comment

begin_define
define|#
directive|define
name|KICONV_FROM_LOWER
value|4
end_define

begin_comment
comment|/* tolower source character, then convert */
end_comment

begin_define
define|#
directive|define
name|KICONV_FROM_UPPER
value|8
end_define

begin_comment
comment|/* toupper source character, then convert */
end_comment

begin_comment
comment|/*  * Entry for cslist sysctl  */
end_comment

begin_define
define|#
directive|define
name|ICONV_CSPAIR_INFO_VER
value|1
end_define

begin_struct
struct|struct
name|iconv_cspair_info
block|{
name|int
name|cs_version
decl_stmt|;
name|int
name|cs_id
decl_stmt|;
name|int
name|cs_base
decl_stmt|;
name|int
name|cs_refcount
decl_stmt|;
name|char
name|cs_to
index|[
name|ICONV_CSNMAXLEN
index|]
decl_stmt|;
name|char
name|cs_from
index|[
name|ICONV_CSNMAXLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Paramters for 'add' sysctl  */
end_comment

begin_define
define|#
directive|define
name|ICONV_ADD_VER
value|1
end_define

begin_struct
struct|struct
name|iconv_add_in
block|{
name|int
name|ia_version
decl_stmt|;
name|char
name|ia_converter
index|[
name|ICONV_CNVNMAXLEN
index|]
decl_stmt|;
name|char
name|ia_to
index|[
name|ICONV_CSNMAXLEN
index|]
decl_stmt|;
name|char
name|ia_from
index|[
name|ICONV_CSNMAXLEN
index|]
decl_stmt|;
name|int
name|ia_datalen
decl_stmt|;
specifier|const
name|void
modifier|*
name|ia_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iconv_add_out
block|{
name|int
name|ia_csid
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
define|#
directive|define
name|ENCODING_UNICODE
value|"ISO-10646-UCS-2"
define|#
directive|define
name|KICONV_VENDOR_MICSFT
value|1
comment|/* Microsoft Vendor Code for quirk */
name|int
name|kiconv_add_xlat_table
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kiconv_add_xlat16_cspair
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kiconv_add_xlat16_cspairs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kiconv_add_xlat16_table
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|kiconv_quirkcs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_comment
comment|/* can't avoid that */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* can't avoid that */
end_comment

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_comment
comment|/* can't avoid that */
end_comment

begin_struct_decl
struct_decl|struct
name|iconv_cspair
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iconv_cspairdata
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * iconv converter class definition  */
end_comment

begin_struct
struct|struct
name|iconv_converter_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|iconv_converter_class
argument_list|)
name|cc_link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iconv_cspair
block|{
name|int
name|cp_id
decl_stmt|;
comment|/* unique id of charset pair */
name|int
name|cp_refcount
decl_stmt|;
comment|/* number of references from other pairs */
specifier|const
name|char
modifier|*
name|cp_from
decl_stmt|;
specifier|const
name|char
modifier|*
name|cp_to
decl_stmt|;
name|void
modifier|*
name|cp_data
decl_stmt|;
name|struct
name|iconv_converter_class
modifier|*
name|cp_dcp
decl_stmt|;
name|struct
name|iconv_cspair
modifier|*
name|cp_base
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|iconv_cspair
argument_list|)
name|cp_link
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KICONV_CONVERTER
parameter_list|(
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|static DEFINE_CLASS(iconv_ ## name, iconv_ ## name ## _methods, (size)); \     static moduledata_t iconv_ ## name ## _mod = {	\ 	"iconv_"#name, iconv_converter_handler,		\ 	(void*)&iconv_ ## name ## _class		\     };							\     DECLARE_MODULE(iconv_ ## name, iconv_ ## name ## _mod, SI_SUB_DRIVERS, SI_ORDER_ANY);
end_define

begin_define
define|#
directive|define
name|KICONV_CES
parameter_list|(
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|static DEFINE_CLASS(iconv_ces_ ## name, iconv_ces_ ## name ## _methods, (size)); \     static moduledata_t iconv_ces_ ## name ## _mod = {	\ 	"iconv_ces_"#name, iconv_cesmod_handler,	\ 	(void*)&iconv_ces_ ## name ## _class		\     };							\     DECLARE_MODULE(iconv_ces_ ## name, iconv_ces_ ## name ## _mod, SI_SUB_DRIVERS, SI_ORDER_ANY);
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ICONV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Basic conversion functions  */
end_comment

begin_function_decl
name|int
name|iconv_open
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|void
modifier|*
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_close
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_conv
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_conv_case
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|,
name|int
name|casetype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_convchr
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_convchr_case
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|,
name|int
name|casetype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|iconv_convstr
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|iconv_convmem
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_vfs_refcount
parameter_list|(
specifier|const
name|char
modifier|*
name|fsname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bridge struct of iconv functions  */
end_comment

begin_struct
struct|struct
name|iconv_functions
block|{
name|int
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|void
modifier|*
modifier|*
name|handle
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|conv
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|conv_case
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|,
name|int
name|casetype
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|convchr
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|convchr_case
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|inbuf
parameter_list|,
name|size_t
modifier|*
name|inbytesleft
parameter_list|,
name|char
modifier|*
modifier|*
name|outbuf
parameter_list|,
name|size_t
modifier|*
name|outbytesleft
parameter_list|,
name|int
name|casetype
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFS_DECLARE_ICONV
parameter_list|(
name|fsname
parameter_list|)
define|\
value|static struct iconv_functions fsname ## _iconv_core = {		\ 		iconv_open,						\ 		iconv_close,						\ 		iconv_conv,						\ 		iconv_conv_case,					\ 		iconv_convchr,						\ 		iconv_convchr_case					\ 	};								\ 	extern struct iconv_functions *fsname ## _iconv;		\ 	static int fsname ## _iconv_mod_handler(module_t mod,		\ 		int type, void *d);					\ 	static int							\ 	fsname ## _iconv_mod_handler(module_t mod, int type, void *d)	\ 	{								\ 		int error = 0;						\ 		switch(type) {						\ 		case MOD_LOAD:						\ 			fsname ## _iconv =& fsname ## _iconv_core;	\ 			break;						\ 		case MOD_UNLOAD:					\ 			error = iconv_vfs_refcount(#fsname);		\ 			if (error)					\ 				return (EBUSY);				\ 			fsname ## _iconv = NULL;			\ 			break;						\ 		default:						\ 			error = EINVAL;					\ 			break;						\ 		}							\ 		return (error);						\ 	}								\ 	static moduledata_t fsname ## _iconv_mod = {			\ 		#fsname"_iconv",					\ 		fsname ## _iconv_mod_handler,				\ 		NULL							\ 	};								\ 	DECLARE_MODULE(fsname ## _iconv, fsname ## _iconv_mod,		\ 		       SI_SUB_DRIVERS, SI_ORDER_ANY);			\ 	MODULE_DEPEND(fsname ## _iconv, fsname, 1, 1, 1);		\ 	MODULE_DEPEND(fsname ## _iconv, libiconv, 2, 2, 2);		\ 	MODULE_VERSION(fsname ## _iconv, 1)
end_define

begin_comment
comment|/*  * Internal functions  */
end_comment

begin_function_decl
name|int
name|iconv_lookupcp
parameter_list|(
name|char
modifier|*
modifier|*
name|cpp
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_converter_initstub
parameter_list|(
name|struct
name|iconv_converter_class
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_converter_donestub
parameter_list|(
name|struct
name|iconv_converter_class
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iconv_converter_handler
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ICONV_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ICDEBUG
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
value|printf("%s: "format, __func__ , __VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ICDEBUG
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ICONV_H_ */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xdr_ld.h - xdr for additional dbxWorks structures */
end_comment

begin_comment
comment|/*  Copyright 1992 Free Software Foundation, Inc.      This code was donated by Wind River Systems, Inc. */
end_comment

begin_comment
comment|/* modification history -------------------- 01a,05jun90,llk  extracted from xdr_dbx.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCxdrldh
end_ifndef

begin_define
define|#
directive|define
name|INCxdrldh
end_define

begin_define
define|#
directive|define
name|MAXSTRLEN
value|256
end_define

begin_define
define|#
directive|define
name|MAXTBLSZ
value|100
end_define

begin_comment
comment|/*  * structure used to pass back the information for a single file  * loaded in VxWorks  */
end_comment

begin_struct
struct|struct
name|ldfile
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|txt_addr
decl_stmt|;
name|int
name|data_addr
decl_stmt|;
name|int
name|bss_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ldfile
name|ldfile
typedef|;
end_typedef

begin_comment
comment|/*  * structure used to return a list of all files loaded over to   * VxWorks. (VX_STATE_INQ return)  */
end_comment

begin_struct
struct|struct
name|ldtabl
block|{
name|u_int
name|tbl_size
decl_stmt|;
name|ldfile
modifier|*
name|tbl_ent
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ldtabl
name|ldtabl
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_ldfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_ldtabl
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|INCxdrldh
end_endif

end_unit


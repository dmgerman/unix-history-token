begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)htable.h	4.1 (Berkeley) %G%	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * common definitions for htable  */
end_comment

begin_struct
struct|struct
name|addr
block|{
name|u_long
name|addr_val
decl_stmt|;
name|struct
name|addr
modifier|*
name|addr_link
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|name
block|{
name|char
modifier|*
name|name_val
decl_stmt|;
name|struct
name|name
modifier|*
name|name_link
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|alloc_addr
parameter_list|(
name|dummy
parameter_list|)
value|((struct addr *) malloc(sizeof(struct addr)))
end_define

begin_define
define|#
directive|define
name|free_addr
parameter_list|(
name|x
parameter_list|)
value|free((char *) x)
end_define

begin_define
define|#
directive|define
name|NOADDR
value|((struct addr *) 0)
end_define

begin_define
define|#
directive|define
name|net
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|host
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|lhost
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|imp
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|alloc_name
parameter_list|(
name|dummy
parameter_list|)
value|((struct name *) malloc(sizeof(struct name)))
end_define

begin_define
define|#
directive|define
name|free_name
parameter_list|(
name|x
parameter_list|)
value|free(x->name_val); \ 				free((char *) x)
end_define

begin_define
define|#
directive|define
name|NONAME
value|((struct name *) 0)
end_define

begin_define
define|#
directive|define
name|KW_NET
value|1
end_define

begin_define
define|#
directive|define
name|KW_GATEWAY
value|2
end_define

begin_define
define|#
directive|define
name|KW_HOST
value|3
end_define

begin_function_decl
name|struct
name|name
modifier|*
name|newname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input file name */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: lsb_addr_comp.h,v 1.6 1996/10/05 00:18:02 joda Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Comparison macros to emulate LSBFIRST comparison results of network  * byte-order quantities  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LSB_ADDR_COMP_DEFS
end_ifndef

begin_define
define|#
directive|define
name|LSB_ADDR_COMP_DEFS
end_define

begin_comment
comment|/* Compare x and y in VAX byte order, result is -1, 0 or 1. */
end_comment

begin_define
define|#
directive|define
name|krb_lsb_antinet_ulong_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) == (y)) ? 0 :  krb_lsb_antinet_ulong_cmp(x, y))
end_define

begin_define
define|#
directive|define
name|krb_lsb_antinet_ushort_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) == (y)) ? 0 : krb_lsb_antinet_ushort_cmp(x, y))
end_define

begin_function_decl
name|int
name|krb_lsb_antinet_ulong_cmp
parameter_list|(
name|u_int32_t
name|x
parameter_list|,
name|u_int32_t
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_lsb_antinet_ushort_cmp
parameter_list|(
name|u_int16_t
name|x
parameter_list|,
name|u_int16_t
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|lsb_time
parameter_list|(
name|time_t
name|t
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|src
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  LSB_ADDR_COMP_DEFS */
end_comment

end_unit


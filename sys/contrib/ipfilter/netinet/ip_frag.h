begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1993, 1994, 1995 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * @(#)ip_frag.h	1.5 3/24/96  * $Id: ip_frag.h,v 2.0.1.1 1997/01/09 15:14:43 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_FRAG_H_
end_ifndef

begin_define
define|#
directive|define
name|__IP_FRAG_H__
end_define

begin_define
define|#
directive|define
name|IPFT_SIZE
value|257
end_define

begin_typedef
typedef|typedef
struct|struct
name|ipfr
block|{
name|struct
name|ipfr
modifier|*
name|ipfr_next
decl_stmt|,
modifier|*
name|ipfr_prev
decl_stmt|;
name|struct
name|in_addr
name|ipfr_src
decl_stmt|;
name|struct
name|in_addr
name|ipfr_dst
decl_stmt|;
name|u_short
name|ipfr_id
decl_stmt|;
name|u_char
name|ipfr_p
decl_stmt|;
name|u_char
name|ipfr_tos
decl_stmt|;
name|u_short
name|ipfr_off
decl_stmt|;
name|u_short
name|ipfr_ttl
decl_stmt|;
name|u_char
name|ipfr_pass
decl_stmt|;
block|}
name|ipfr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipfrstat
block|{
name|u_long
name|ifs_exists
decl_stmt|;
comment|/* add& already exists */
name|u_long
name|ifs_nomem
decl_stmt|;
name|u_long
name|ifs_new
decl_stmt|;
name|u_long
name|ifs_hits
decl_stmt|;
name|u_long
name|ifs_expire
decl_stmt|;
name|u_long
name|ifs_inuse
decl_stmt|;
name|struct
name|ipfr
modifier|*
modifier|*
name|ifs_table
decl_stmt|;
block|}
name|ipfrstat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFR_CMPSZ
value|(4 + 4 + 2 + 1 + 1)
end_define

begin_function_decl
specifier|extern
name|ipfrstat_t
modifier|*
name|ipfr_fragstats
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|ipfr_newfrag
argument_list|()
decl_stmt|,
name|ipfr_knownfrag
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ipfr_unload
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_FIL_H__ */
end_comment

end_unit


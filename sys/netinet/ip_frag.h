begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-2000 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * @(#)ip_frag.h	1.5 3/24/96  * $Id: ip_frag.h,v 2.2 1999/08/06 06:26:38 darrenr Exp $  * $FreeBSD$  #ifndef	__IP_FRAG_H__ #define	__IP_FRAG_H__  #define	IPFT_SIZE	257  typedef	struct	ipfr	{ 	struct	ipfr	*ipfr_next, *ipfr_prev; 	void	*ipfr_data; 	struct	in_addr	ipfr_src; 	struct	in_addr	ipfr_dst; 	u_short	ipfr_id; 	u_char	ipfr_p; 	u_char	ipfr_tos; 	u_short	ipfr_off; 	u_short	ipfr_ttl; 	frentry_t *ipfr_rule; } ipfr_t;   typedef	struct	ipfrstat { 	u_long	ifs_exists;	/* add& already exists */
end_comment

begin_decl_stmt
name|u_long
name|ifs_nomem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|ifs_new
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|ifs_hits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|ifs_expire
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|ifs_inuse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ipfr
modifier|*
modifier|*
name|ifs_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ipfr
modifier|*
modifier|*
name|ifs_nattab
decl_stmt|;
end_decl_stmt

begin_empty_stmt
unit|} ipfrstat_t
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|IPFR_CMPSZ
value|(4 + 4 + 2 + 1 + 1)
end_define

begin_decl_stmt
specifier|extern
name|int
name|fr_ipfrttl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_frag_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipfrstat_t
modifier|*
name|ipfr_fragstats
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfr_newfrag
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfr_nat_newfrag
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipfr_nat_knownfrag
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|ipfr_knownfrag
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipfr_forget
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipfr_unload
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipfr_fragexpire
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
name|BSD
operator|>=
literal|199306
operator|)
operator|||
name|SOLARIS
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOLARIS2
argument_list|)
operator|&&
operator|(
name|SOLARIS2
operator|<
literal|7
operator|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|ipfr_slowtimer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|ipfr_slowtimer
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|ipfr_slowtimer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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


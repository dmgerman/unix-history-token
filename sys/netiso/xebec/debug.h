begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/xebec/Attic/debug.h,v $ */
end_comment

begin_define
define|#
directive|define
name|OUT
value|stdout
end_define

begin_decl_stmt
specifier|extern
name|int
name|debug
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|column
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFDEBUG
parameter_list|(
name|letter
parameter_list|)
define|\
value|if(debug['letter']) {
end_define

begin_define
define|#
directive|define
name|ENDDEBUG
value|; (void) fflush(stdout);}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STAR
value|*
end_define

begin_define
define|#
directive|define
name|IFDEBUG
parameter_list|(
name|letter
parameter_list|)
end_define

begin_comment
comment|//*beginning of comment*/STAR
end_comment

begin_define
define|#
directive|define
name|ENDDEBUG
value|STAR
comment|/*end of comment*/
value|/
end_define

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

end_unit


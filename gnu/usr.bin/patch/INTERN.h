begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /home/ncvs/src/gnu/usr.bin/patch/INTERN.h,v 1.2 1995/05/30 05:02:27 rgrimes Exp $  *  * $Log: INTERN.h,v $  * Revision 1.2  1995/05/30 05:02:27  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1993/06/19  14:21:52  paul  * b-maked patch-2.10  *  * Revision 2.0  86/09/17  15:35:58  lwall  * Baseline for netwide release.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXT
end_ifdef

begin_undef
undef|#
directive|undef
name|EXT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INIT
end_ifdef

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
value|= x
end_define

begin_define
define|#
directive|define
name|DOINIT
end_define

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: INTERN.h,v 7.0.1.1 86/12/12 16:51:45 lwall Exp $  *  * $Log:	INTERN.h,v $  * Revision 7.0.1.1  86/12/12  16:51:45  lwall  * Guarded the undefs.  *   * Revision 7.0  86/10/08  15:11:37  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
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


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: EXTERN.h,v 7.0.1.1 86/12/12 16:46:50 lwall Exp $  *  * $Log:	EXTERN.h,v $  * Revision 7.0.1.1  86/12/12  16:46:50  lwall  * Guarded the undefs.  *   * Revision 7.0  86/10/08  15:11:31  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
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
value|extern
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
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_undef
undef|#
directive|undef
name|DOINIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************** *                            COPYRIGHT NOTICE                              * **************************************************************************** *                ncurses is copyright (C) 1992-1995                        * *                          Zeyd M. Ben-Halim                               * *                          zmbenhal@netcom.com                             * *                          Eric S. Raymond                                 * *                          esr@snark.thyrsus.com                           * *                                                                          * *        Permission is hereby granted to reproduce and distribute ncurses  * *        by any means and for any fee, whether alone or as part of a       * *        larger distribution, in source or in binary form, PROVIDED        * *        this notice is included with any such distribution, and is not    * *        removed from any of its header files. Mention of ncurses in any   * *        applications linked with it is highly appreciated.                * *                                                                          * *        ncurses comes AS IS with no warranty, implied or expressed.       * *                                                                          * ***************************************************************************/
end_comment

begin_comment
comment|/*  * unctrl.h  *  * Display a printable version of a control character.  * Control characters are displayed in caret notation (^x), DELETE is displayed  * as ^?. Printable characters are displayed as is.  *  * The returned pointer points to a static buffer which gets overwritten by  * each call. Therefore, you must copy the resulting string to a safe place  * before calling unctrl() again.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNCTRL_H
end_ifndef

begin_define
define|#
directive|define
name|_UNCTRL_H
value|1
end_define

begin_undef
undef|#
directive|undef
name|NCURSES_VERSION
end_undef

begin_define
define|#
directive|define
name|NCURSES_VERSION
value|"1.8.6/ache"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<ncurses.h>
specifier|extern
name|char
modifier|*
name|unctrl
parameter_list|(
name|chtype
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNCTRL_H */
end_comment

end_unit


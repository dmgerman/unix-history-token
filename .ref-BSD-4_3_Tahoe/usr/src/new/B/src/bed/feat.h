begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: feat.h,v 2.4 85/08/22 16:02:40 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- #define features, to make it easy to turn them off.  */
end_comment

begin_define
define|#
directive|define
name|BTOP
value|1
end_define

begin_comment
comment|/* Editor used as front-end to interpreter */
end_comment

begin_comment
comment|/* 	 * (This used to be an optional feature of the editor, but is now 	 * the only officially acknowledged way of using the B system. 	 * Non-UNIX systems may have no choice but to turn it off, because 	 * it heavily depends on features like forks and pipes. 	 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMALLSYS
end_ifndef

begin_comment
comment|/*  * The #define SMALLSYS squeezes out some lesser important debugging  * code, while leaving out the following #defines turns off various  * features which can be missed (according to the author).  * They are roughly sorted on amount of code saved, greatest  * saving first.  */
end_comment

begin_define
define|#
directive|define
name|SAVEBUF
value|1
end_define

begin_comment
comment|/* Save Copy Buffer on file between edit sessions */
end_comment

begin_define
define|#
directive|define
name|USERSUGG
value|1
end_define

begin_comment
comment|/* Give suggestions for user-defined commands */
end_comment

begin_define
define|#
directive|define
name|SAVEPOS
value|1
end_define

begin_comment
comment|/* Save focus position between edit sessions */
end_comment

begin_define
define|#
directive|define
name|FILEARGS
value|1
end_define

begin_comment
comment|/* Allow 'stand-alone' editor to edit single units */
end_comment

begin_define
define|#
directive|define
name|RECORDING
value|1
end_define

begin_comment
comment|/* [record] and [playback] commands */
end_comment

begin_define
define|#
directive|define
name|SCROLLBAR
value|1
end_define

begin_comment
comment|/* Show scroll bar if unit> screen */
end_comment

begin_define
define|#
directive|define
name|SHOWBUF
value|1
end_define

begin_comment
comment|/* Shows contents of copy buffer if locked */
end_comment

begin_comment
comment|/*  * The following feature used to fit, even on a (our) PDP-11/45.  * And as it is very useful for novice users, you might try to let it stay.  */
end_comment

begin_define
define|#
directive|define
name|HELPFUL
value|1
end_define

begin_comment
comment|/* Print help blurb on ESC-? or ? */
end_comment

begin_endif
endif|#
directive|endif
endif|!SMALLSYS
end_endif

begin_comment
comment|/*  * On compilers that implement C according to the Kernighan and Ritchie book,  * but not the unix v7 extensions, turn off the following definition.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTASS
value|1
end_define

begin_comment
comment|/* C compiler knows structure assignment */
end_comment

end_unit


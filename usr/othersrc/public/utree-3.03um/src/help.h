begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      HELP.H  *      UTREE help definitions.  *      3.01-um klin, Sat Apr 20 11:02:33 1991  *      3.03-um klin, Sat Feb 15 18:33:14 1992, Minor changes  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MAIN_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid_help
index|[]
init|=
literal|"@(#) utree 3.03-um (klin) Feb 15 1992 help.h"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_&& !lint */
end_comment

begin_comment
comment|/* Max length of a menu item in the help menuline                       */
end_comment

begin_define
define|#
directive|define
name|ITEMLEN
value|16
end_define

begin_comment
comment|/*  *      Utree help pages are hold in a dynamically linked list of the  *      following data structure _hlist which is built up at runtime.  *      The record contains information about help items from a help  *      file, i.e. a menu title or item, the starting position of a help  *      page about this item in the help file and the number of lines  *      of this help page. Displaying a help page about an item is  *      therefore searching this item in the help page list, positioning  *      to the starting position in the help file and putting as many  *      lines from the helpfile to screen as this help page has.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hlist
block|{
name|char
name|item
index|[
name|ITEMLEN
index|]
decl_stmt|;
comment|/* Menu line item                       */
name|char
name|hotkey
decl_stmt|;
comment|/* Menu hot key                         */
name|int
name|nlines
decl_stmt|;
comment|/* Number of lines in help file         */
name|long
name|position
decl_stmt|;
comment|/* Start position in help file          */
name|struct
name|_hlist
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to next help page            */
block|}
name|hlist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HNULL
value|((hlist *) 0)
end_define

begin_comment
comment|/* The hlist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Access to items of hlist record is done with macros  *      to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|HITEM
parameter_list|(
name|p
parameter_list|)
value|((p)->item)
end_define

begin_define
define|#
directive|define
name|HHKEY
parameter_list|(
name|p
parameter_list|)
value|((p)->hotkey)
end_define

begin_define
define|#
directive|define
name|HNLIN
parameter_list|(
name|p
parameter_list|)
value|((p)->nlines)
end_define

begin_define
define|#
directive|define
name|HSPOS
parameter_list|(
name|p
parameter_list|)
value|((p)->position)
end_define

begin_define
define|#
directive|define
name|HNEXT
parameter_list|(
name|p
parameter_list|)
value|((p)->next)
end_define

end_unit


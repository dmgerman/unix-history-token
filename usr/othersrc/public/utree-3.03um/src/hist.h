begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      HIST.H  *      UTREE history list definitions.  *      3.03-um klin, Tue Feb 11 22:35:29 1992, Shell command history added  *            d klin, Thu Apr  2 09:07:41 1992, Time stamps for history added  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
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
name|sccsid_hist
index|[]
init|=
literal|"@(#) utree 3.03d-um (klin) Apr  2 1992 hist.h"
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
comment|/*  *      Shell commands are hold in a dynamically lined list of  *      struct _clist.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_clist
block|{
name|glist
name|list
decl_stmt|;
comment|/* Containing command and pointers      */
name|int
name|length
decl_stmt|;
comment|/* Length of current command            */
name|int
name|number
decl_stmt|;
comment|/* Event number                         */
name|int
name|counter
decl_stmt|;
comment|/* Event counter                        */
name|time_t
name|time
decl_stmt|;
comment|/* Time stamp                           */
block|}
name|clist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CHNULL
value|((clist *) 0)
end_define

begin_comment
comment|/* The clist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Access to entries in the command history list is done  *      with macros to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|CHLST
parameter_list|(
name|p
parameter_list|)
value|(&(p)->list)
end_define

begin_define
define|#
directive|define
name|CHCMD
parameter_list|(
name|p
parameter_list|)
value|((p)->list.string)
end_define

begin_define
define|#
directive|define
name|CHPRV
parameter_list|(
name|p
parameter_list|)
value|((p)->list.prev)
end_define

begin_define
define|#
directive|define
name|CHNXT
parameter_list|(
name|p
parameter_list|)
value|((p)->list.next)
end_define

begin_define
define|#
directive|define
name|CHLEN
parameter_list|(
name|p
parameter_list|)
value|((p)->length)
end_define

begin_define
define|#
directive|define
name|CHNUM
parameter_list|(
name|p
parameter_list|)
value|((p)->number)
end_define

begin_define
define|#
directive|define
name|CHCNT
parameter_list|(
name|p
parameter_list|)
value|((p)->counter)
end_define

begin_define
define|#
directive|define
name|CHTIM
parameter_list|(
name|p
parameter_list|)
value|((p)->time)
end_define

end_unit


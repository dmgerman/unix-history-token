begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dishhelp.c - */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/quipu/dish/RCS/dishhelp.c,v 7.6 91/02/22 09:40:27 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/quipu/dish/RCS/dishhelp.c,v 7.6 91/02/22 09:40:27 mrose Interim $  *  *  * $Log:	dishhelp.c,v $  * Revision 7.6  91/02/22  09:40:27  mrose  * Interim 6.8  *   * Revision 7.5  90/10/17  11:55:17  mrose  * sync  *   * Revision 7.4  90/07/09  14:47:05  mrose  * sync  *   * Revision 7.3  90/04/18  08:49:34  mrose  * 6.2  *   * Revision 7.2  90/03/15  11:18:21  mrose  * quipu-sync  *   * Revision 7.1  90/01/11  18:37:37  mrose  * real-sync  *   * Revision 7.0  89/11/23  22:20:03  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_define
define|#
directive|define
name|OPT
value|(!frompipe || rps -> ps_byteno == 0 ? opt : rps)
end_define

begin_define
define|#
directive|define
name|RPS
value|(!frompipe || opt -> ps_byteno == 0 ? rps : opt)
end_define

begin_decl_stmt
specifier|extern
name|char
name|frompipe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PS
name|opt
decl_stmt|,
name|rps
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXARG
value|50
end_define

begin_struct
struct|struct
block|{
name|char
modifier|*
name|command
decl_stmt|;
name|char
modifier|*
name|args
decl_stmt|;
name|char
name|serv
decl_stmt|;
name|char
name|other
decl_stmt|;
name|char
modifier|*
name|use
decl_stmt|;
block|}
name|help_info
index|[
name|MAXARG
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|num_help
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|add_dish_help
argument_list|(
argument|command
argument_list|,
argument|args
argument_list|,
argument|serv
argument_list|,
argument|other
argument_list|,
argument|use
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|args
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|serv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|other
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|use
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|help_info
index|[
name|num_help
index|]
operator|.
name|command
operator|=
name|command
expr_stmt|;
name|help_info
index|[
name|num_help
index|]
operator|.
name|args
operator|=
name|args
expr_stmt|;
name|help_info
index|[
name|num_help
index|]
operator|.
name|serv
operator|=
name|serv
expr_stmt|;
name|help_info
index|[
name|num_help
index|]
operator|.
name|other
operator|=
name|other
expr_stmt|;
name|help_info
index|[
name|num_help
index|]
operator|.
name|use
operator|=
name|use
expr_stmt|;
name|num_help
operator|++
expr_stmt|;
block|}
end_block

begin_macro
name|dish_help_init
argument_list|()
end_macro

begin_block
block|{
name|add_dish_help
argument_list|(
literal|"dish"
argument_list|,
literal|"[-pipe] [-noconnect] [-user<name>]\n[-password [<password>]] [-call<dsa name>] [-fast]\n[-simple] [-protected] [-strong] [-noauthentication]"
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|"Directory Shell,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"showentry"
argument_list|,
literal|"[-[no]cache] [-[no]name] [-[no]move]"
argument_list|,
name|TRUE
argument_list|,
name|TRUE
argument_list|,
literal|"show an entry, read it if not cached,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"list"
argument_list|,
literal|"[-nocache] [-noshow] [-[no]move]"
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
literal|"list children of the current node"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"search"
argument_list|,
literal|"[-baseobject] [-singlelevel] [-subtree]\n[-filter<filter>]\n[-[no]relative] [-[no]searchaliases] [-[no]partial] [-hitone]\n[-fred [-expand] [-full] [-summary] [-nofredseq] [-subdisplay]]"
argument_list|,
name|TRUE
argument_list|,
name|TRUE
argument_list|,
literal|"search the tree for an object,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"moveto"
argument_list|,
literal|"[-[no]pwd] [-[no]check] [-sequence<name>] [-nosequence]<position>"
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|"move to position in the DIT"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"modify"
argument_list|,
literal|"[-draft<draft> [-noedit]] [-newdraft]\n[-add<attr type>=<attr value>] [-remove<attr type>=<attr value>] "
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
literal|"modify an existing node,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"showname"
argument_list|,
literal|"[-[no]compact] [-[no]ufn] [-[no]cache]"
argument_list|,
name|TRUE
argument_list|,
name|TRUE
argument_list|,
literal|"show the name of an entry,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"compare"
argument_list|,
literal|"-attribute<attributeType '=' attributeValue>\n[-[no]print]"
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
literal|"compare attribute with the supplied value,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"add"
argument_list|,
literal|"[-draft<draft> [-noedit]] [-template<draft>] [-newdraft]\n [-objectclass<objectclass>]"
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
literal|"add a new node,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"delete"
argument_list|,
literal|""
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
literal|"delete an object,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"modifyrdn"
argument_list|,
literal|"-name<attributeType '=' attributeValue> [-[no]delete]"
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
literal|"modify the name of a node,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"squid"
argument_list|,
literal|"[-sequence<name>] [-alias<position>] [-version]\n[-user] [-syntax] [-fred]"
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|"status of dish,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"bind"
argument_list|,
literal|"[-noconnect] [[-user]<name>]\n[-password [<password>]] [-[no]refer]\n[-call<dsa name>]\n[-simple] [-protected] [-strong] [-noauthentication]"
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|"connect to the directory,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"unbind"
argument_list|,
literal|"[-noquit]"
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|"disconnect from the directory,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"fred"
argument_list|,
literal|"[-display<name>]\n[-dm2dn [-list] [-phone] [-photo]<domain-or-mailbox>]\n[-expand [-full]<DN>]\n[-ufn [-list,][-mailbox,][-phone,][-photo,]<name...>]\n[-ufnrc<list...>]"
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|"back-end to fred,"
argument_list|)
expr_stmt|;
name|add_dish_help
argument_list|(
literal|"dsacontrol"
argument_list|,
literal|"[-[un]lock<entry>] [-dump<directory>]\n[-tailor<string>] [-abort] [-restart] [-info]\n[-refresh<entry>] [-resync<entry>] [-slave [<entry>]]"
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|"control the operation of the DSA (managers only),"
argument_list|)
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|Usage
argument_list|(
argument|rtn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|rtn
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|DN
name|dn
decl_stmt|,
name|savename
decl_stmt|;
name|int
name|i
decl_stmt|;
name|dn_free
argument_list|(
name|dn
argument_list|)
expr_stmt|;
name|dn
operator|=
name|savename
expr_stmt|;
name|savename
operator|=
name|NULLDN
expr_stmt|;
if|if
condition|(
name|print_arg_error
argument_list|(
name|OPT
argument_list|)
operator|==
name|OK
condition|)
return|return;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|help_info
index|[
name|i
index|]
operator|.
name|command
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|help_info
index|[
name|i
index|]
operator|.
name|command
argument_list|,
name|rtn
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|help_info
index|[
name|i
index|]
operator|.
name|serv
condition|)
block|{
name|ps_printf
argument_list|(
name|OPT
argument_list|,
literal|"Usage %s [-help] [<object>] %s \n"
argument_list|,
name|rtn
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|args
argument_list|)
expr_stmt|;
name|print_other
argument_list|(
name|OPT
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|other
argument_list|)
expr_stmt|;
name|ps_printf
argument_list|(
name|OPT
argument_list|,
literal|"\n[<service controls>]\n"
argument_list|)
expr_stmt|;
block|}
else|else
name|ps_printf
argument_list|(
name|OPT
argument_list|,
literal|"Usage %s [-help] %s\n"
argument_list|,
name|rtn
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|args
argument_list|)
expr_stmt|;
return|return;
block|}
name|ps_print
argument_list|(
name|OPT
argument_list|,
literal|"Usage...\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|help_arg
argument_list|(
argument|rtn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|rtn
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|help_info
index|[
name|i
index|]
operator|.
name|command
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|help_info
index|[
name|i
index|]
operator|.
name|command
argument_list|,
name|rtn
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|help_info
index|[
name|i
index|]
operator|.
name|serv
condition|)
block|{
name|ps_printf
argument_list|(
name|RPS
argument_list|,
literal|"%-10s - %s\n[<object>] %s "
argument_list|,
name|rtn
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|use
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|args
argument_list|)
expr_stmt|;
name|print_other
argument_list|(
name|RPS
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|other
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|print_service
argument_list|()
expr_stmt|;
block|}
else|else
name|ps_printf
argument_list|(
name|RPS
argument_list|,
literal|"%-10s - %s\n%s\n"
argument_list|,
name|rtn
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|use
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|args
argument_list|)
expr_stmt|;
return|return;
block|}
name|ps_print
argument_list|(
name|OPT
argument_list|,
literal|"Sorry - No help available\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|print_other
argument_list|(
argument|aps
argument_list|,
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|PS
name|aps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|x
operator|==
name|FALSE
condition|)
return|return;
name|ps_print
argument_list|(
name|aps
argument_list|,
literal|"\n[-[no]types<attribute-type> *] [-[no]all]\n[-[no]value] [-[no]show] \n[-[no]key] [-edb]\n[-proc<syntax><process>]"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|print_service
argument_list|()
end_macro

begin_block
block|{
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-sequence<name>] [-nosequence]\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-[no]preferchain] [-[no]chaining]\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-[dont]usecopy] [-[dont]dereferencealias]\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-low] [-medium] [-high]\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-timelimit n] [-notimelimit]\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-sizelimit n] [-nosizelimit]\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-strong] [-[no]refer]\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"[-[no]localscope] [-help]\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|call_help
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"The following commands are recognised...\n\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|help_info
index|[
name|i
index|]
operator|.
name|command
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
name|ps_printf
argument_list|(
name|RPS
argument_list|,
literal|"%-10s - %s\n"
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|command
argument_list|,
name|help_info
index|[
name|i
index|]
operator|.
name|use
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"\nEnter<command> -help for help on that command\n"
argument_list|)
expr_stmt|;
name|ps_print
argument_list|(
name|RPS
argument_list|,
literal|"See the DISH manual for full details\n\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* infodoc.c -- Functions which build documentation nodes.    $Id: infodoc.c,v 1.28 2002/02/27 13:37:33 karl Exp $     Copyright (C) 1993, 97, 98, 99, 2001, 02 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"funs.h"
end_include

begin_comment
comment|/* HELP_NODE_GETS_REGENERATED is always defined now that keys may get    rebound, or other changes in the help text may occur.  */
end_comment

begin_define
define|#
directive|define
name|HELP_NODE_GETS_REGENERATED
value|1
end_define

begin_comment
comment|/* The name of the node used in the help window. */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|info_help_nodename
init|=
literal|"*Info Help*"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A node containing printed key bindings and their documentation. */
end_comment

begin_decl_stmt
specifier|static
name|NODE
modifier|*
name|internal_info_help_node
init|=
operator|(
name|NODE
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A pointer to the contents of the help node. */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|internal_info_help_node_contents
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The (more or less) static text which appears in the internal info    help node.  The actual key bindings are inserted.  Keep the     underlines (****, etc.) in the same N_ call as  the text lines they    refer to, so translations can make the number of *'s or -'s match.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INFOKEY
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|info_internal_help_text
index|[]
init|=
block|{
name|N_
argument_list|(
literal|"Basic Commands in Info Windows\n\ ******************************\n"
argument_list|)
block|,
literal|"\n"
block|,
name|N_
argument_list|(
literal|"\\%-10[quit-help]  Quit this help.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[quit]  Quit Info altogether.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[get-info-help-node]  Invoke the Info tutorial.\n"
argument_list|)
block|,
literal|"\n"
block|,
name|N_
argument_list|(
literal|"Selecting other nodes:\n\ ----------------------\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[next-node]  Move to the \"next\" node of this node.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[prev-node]  Move to the \"previous\" node of this node.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[up-node]  Move \"up\" from this node.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[menu-item]  Pick menu item specified by name.\n\               Picking a menu item causes another node to be selected.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[xref-item]  Follow a cross reference.  Reads name of reference.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[history-node]  Move to the last node seen in this window.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[move-to-next-xref]  Skip to next hypertext link within this node.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[move-to-prev-xref]  Skip to previous hypertext link within this node.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[select-reference-this-line]  Follow the hypertext link under cursor.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[dir-node]  Move to the `directory' node.  Equivalent to `\\[goto-node] (DIR)'.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[top-node]  Move to the Top node.  Equivalent to `\\[goto-node] Top'.\n"
argument_list|)
block|,
literal|"\n"
block|,
name|N_
argument_list|(
literal|"Moving within a node:\n\ ---------------------\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[scroll-forward]  Scroll forward a page.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[scroll-backward]  Scroll backward a page.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[beginning-of-node]  Go to the beginning of this node.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[end-of-node]  Go to the end of this node.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[scroll-forward]  Scroll forward 1 line.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[scroll-backward]  Scroll backward 1 line.\n"
argument_list|)
block|,
literal|"\n"
block|,
name|N_
argument_list|(
literal|"Other commands:\n\ ---------------\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[menu-digit]  Pick first ... ninth item in node's menu.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[last-menu-item]  Pick last item in node's menu.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[index-search]  Search for a specified string in the index entries of this Info\n\               file, and select the node referenced by the first entry found.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[goto-node]  Move to node specified by name.\n\               You may include a filename as well, as in (FILENAME)NODENAME.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[search]  Search forward for a specified string\n\               and select the node in which the next occurrence is found.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"\\%-10[search-backward]  Search backward for a specified string\n\               and select the node in which the previous occurrence is found.\n"
argument_list|)
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !INFOKEY */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|info_internal_help_text
index|[]
init|=
block|{
name|N_
argument_list|(
literal|"Basic Commands in Info Windows\n\ ******************************\n"
argument_list|)
block|,
literal|"\n"
block|,
name|N_
argument_list|(
literal|"  %-10s  Quit this help.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"  %-10s  Quit Info altogether.\n"
argument_list|)
block|,
name|N_
argument_list|(
literal|"  %-10s  Invoke the Info tutorial.\n"
argument_list|)
block|,
literal|"\n"
block|,
name|N_
argument_list|(
literal|"Selecting other nodes:\n\ ----------------------\n"
argument_list|,
argument|N_(
literal|"  %-10s  Move to the `next' node of this node.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Move to the `previous' node of this node.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Move `up' from this node.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Pick menu item specified by name.\n"
argument|)
argument_list|,
argument|N_(
literal|"              Picking a menu item causes another node to be selected.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Follow a cross reference.  Reads name of reference.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Move to the last node seen in this window.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Skip to next hypertext link within this node.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Follow the hypertext link under cursor.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Move to the `directory' node.  Equivalent to `g (DIR)'.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Move to the Top node.  Equivalent to `g Top'.\n"
argument|)
argument_list|,
literal|"\n"
argument_list|,
argument|N_(
literal|"Moving within a node:\n\ ---------------------\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Scroll forward a page.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Scroll backward a page.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Go to the beginning of this node.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Go to the end of this node.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Scroll forward 1 line.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Scroll backward 1 line.\n"
argument|)
argument_list|,
literal|"\n"
argument_list|,
argument|N_(
literal|"Other commands:\n\ ---------------\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Pick first ... ninth item in node's menu.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Pick last item in node's menu.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Search for a specified string in the index entries of this Info\n"
argument|)
argument_list|,
argument|N_(
literal|"              file, and select the node referenced by the first entry found.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Move to node specified by name.\n"
argument|)
argument_list|,
argument|N_(
literal|"              You may include a filename as well, as in (FILENAME)NODENAME.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Search forward for a specified string,\n"
argument|)
argument_list|,
argument|N_(
literal|"              and select the node in which the next occurrence is found.\n"
argument|)
argument_list|,
argument|N_(
literal|"  %-10s  Search backward for a specified string\n"
argument|)
argument_list|,
argument|N_(
literal|"              and select the node in which the next occurrence is found.\n"
argument|)
argument_list|,
argument|NULL };  static char *info_help_keys_text[][
literal|2
argument|] = {   {
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"CTRL-x 0"
argument_list|,
literal|"CTRL-x 0"
argument|}
argument_list|,
argument|{
literal|"q"
argument_list|,
literal|"q"
argument|}
argument_list|,
argument|{
literal|"h"
argument_list|,
literal|"ESC h"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"SPC"
argument_list|,
literal|"SPC"
argument|}
argument_list|,
argument|{
literal|"DEL"
argument_list|,
literal|"b"
argument|}
argument_list|,
argument|{
literal|"b"
argument_list|,
literal|"ESC b"
argument|}
argument_list|,
argument|{
literal|"e"
argument_list|,
literal|"ESC e"
argument|}
argument_list|,
argument|{
literal|"ESC 1 SPC"
argument_list|,
literal|"RET"
argument|}
argument_list|,
argument|{
literal|"ESC 1 DEL"
argument_list|,
literal|"y"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"n"
argument_list|,
literal|"CTRL-x n"
argument|}
argument_list|,
argument|{
literal|"p"
argument_list|,
literal|"CTRL-x p"
argument|}
argument_list|,
argument|{
literal|"u"
argument_list|,
literal|"CTRL-x u"
argument|}
argument_list|,
argument|{
literal|"m"
argument_list|,
literal|"ESC m"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"f"
argument_list|,
literal|"ESC f"
argument|}
argument_list|,
argument|{
literal|"l"
argument_list|,
literal|"l"
argument|}
argument_list|,
argument|{
literal|"TAB"
argument_list|,
literal|"TAB"
argument|}
argument_list|,
argument|{
literal|"RET"
argument_list|,
literal|"CTRL-x RET"
argument|}
argument_list|,
argument|{
literal|"d"
argument_list|,
literal|"ESC d"
argument|}
argument_list|,
argument|{
literal|"t"
argument_list|,
literal|"ESC t"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"1-9"
argument_list|,
literal|"ESC 1-9"
argument|}
argument_list|,
argument|{
literal|"0"
argument_list|,
literal|"ESC 0"
argument|}
argument_list|,
argument|{
literal|"i"
argument_list|,
literal|"CTRL-x i"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"g"
argument_list|,
literal|"CTRL-x g"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"s"
argument_list|,
literal|"/"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|{
literal|"ESC - s"
argument_list|,
literal|"?"
argument|}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument|}
argument_list|,
argument|NULL };
endif|#
directive|endif
comment|/* !INFOKEY */
argument|static char *where_is_internal ();  void dump_map_to_message_buffer (prefix, map)      char *prefix;      Keymap map; {   register int i;   unsigned prefix_len = strlen (prefix);   char *new_prefix = (char *)xmalloc (prefix_len +
literal|2
argument|);    strncpy (new_prefix, prefix, prefix_len);   new_prefix[prefix_len +
literal|1
argument|] =
literal|'\0'
argument|;    for (i =
literal|0
argument|; i<
literal|256
argument|; i++)     {       new_prefix[prefix_len] = i;       if (map[i].type == ISKMAP)         {           dump_map_to_message_buffer (new_prefix, (Keymap)map[i].function);         }       else if (map[i].function)         {           register int last;           char *doc
argument_list|,
argument|*name;            doc = function_documentation (map[i].function);           name = function_name (map[i].function);            if (!*doc)             continue;
comment|/* Find out if there is a series of identical functions, as in              ea_insert (). */
argument|for (last = i +
literal|1
argument|; last<
literal|256
argument|; last++)             if ((map[last].type != ISFUNC) ||                 (map[last].function != map[i].function))               break;            if (last -
literal|1
argument|!= i)             {               printf_to_message_buffer (
literal|"%s .. "
argument|, pretty_keyseq (new_prefix)); 	      new_prefix[prefix_len] = last -
literal|1
argument|;               printf_to_message_buffer (
literal|"%s\t"
argument|, pretty_keyseq (new_prefix));               i = last -
literal|1
argument|;             }           else             printf_to_message_buffer (
literal|"%s\t"
argument|, pretty_keyseq (new_prefix));
if|#
directive|if
name|defined
argument_list|(
name|NAMED_FUNCTIONS
argument_list|)
comment|/* Print the name of the function, and some padding before the              documentation string is printed. */
argument|{             int length_so_far;             int desired_doc_start =
literal|40
argument|;
comment|/* Must be multiple of 8. */
argument|printf_to_message_buffer (
literal|"(%s)"
argument|, name);             length_so_far = message_buffer_length_this_line ();              if ((desired_doc_start + strlen (doc))>= the_screen->width)               printf_to_message_buffer (
literal|"\n     "
argument|);             else               {                 while (length_so_far< desired_doc_start)                   {                     printf_to_message_buffer (
literal|"\t"
argument|);                     length_so_far += character_width (
literal|'\t'
argument|, length_so_far);                   }               }           }
endif|#
directive|endif
comment|/* NAMED_FUNCTIONS */
argument|printf_to_message_buffer (
literal|"%s\n"
argument|, doc);         }     }   free (new_prefix); }
comment|/* How to create internal_info_help_node.  HELP_IS_ONLY_WINDOW_P says    whether we're going to end up in a second (or more) window of our    own, or whether there's only one window and we're going to usurp it.    This determines how to quit the help window.  Maybe we should just    make q do the right thing in both cases.  */
argument|static void create_internal_info_help_node (help_is_only_window_p)      int help_is_only_window_p; {   register int i;   NODE *node;   char *contents = NULL;   char *exec_keys;
ifndef|#
directive|ifndef
name|HELP_NODE_GETS_REGENERATED
argument|if (internal_info_help_node_contents)     contents = internal_info_help_node_contents;
endif|#
directive|endif
comment|/* !HELP_NODE_GETS_REGENERATED */
argument|if (!contents)     {       int printed_one_mx =
literal|0
argument|;        initialize_message_buffer ();        for (i =
literal|0
argument|; info_internal_help_text[i]; i++)         {
ifdef|#
directive|ifdef
name|INFOKEY
argument|printf_to_message_buffer (replace_in_documentation (            _(info_internal_help_text[i]), help_is_only_window_p));
else|#
directive|else
comment|/* Don't translate blank lines, gettext outputs the po file              header in that case.  We want a blank line.  */
argument|char *msg = *(info_internal_help_text[i])                       ? _(info_internal_help_text[i])                       : info_internal_help_text[i];           char *key = info_help_keys_text[i][vi_keys_p];
comment|/* If we have only one window (because the window size was too              small to split it), CTRL-x 0 doesn't work to `quit' help.  */
argument|if (STREQ (key,
literal|"CTRL-x 0"
argument|)&& help_is_only_window_p)             key =
literal|"l"
argument|;            printf_to_message_buffer (msg, key);
endif|#
directive|endif
comment|/* !INFOKEY */
argument|}        printf_to_message_buffer (
literal|"---------------------\n\n"
argument|);       printf_to_message_buffer (_(
literal|"The current search path is:\n"
argument|));       printf_to_message_buffer (
literal|"  %s\n"
argument|, infopath);       printf_to_message_buffer (
literal|"---------------------\n\n"
argument|);       printf_to_message_buffer (_(
literal|"Commands available in Info windows:\n\n"
argument|));       dump_map_to_message_buffer (
literal|""
argument|, info_keymap);       printf_to_message_buffer (
literal|"---------------------\n\n"
argument|);       printf_to_message_buffer (_(
literal|"Commands available in the echo area:\n\n"
argument|));       dump_map_to_message_buffer (
literal|""
argument|, echo_area_keymap);
if|#
directive|if
name|defined
argument_list|(
name|NAMED_FUNCTIONS
argument_list|)
comment|/* Get a list of commands which have no keystroke equivs. */
argument|exec_keys = where_is (info_keymap, InfoCmd(info_execute_command));       if (exec_keys)         exec_keys = xstrdup (exec_keys);       for (i =
literal|0
argument|; function_doc_array[i].func; i++)         {           InfoCommand *cmd = DocInfoCmd(&function_doc_array[i]);            if (InfoFunction(cmd) != info_do_lowercase_version&& !where_is_internal (info_keymap, cmd)&& !where_is_internal (echo_area_keymap, cmd))             {               if (!printed_one_mx)                 {                   printf_to_message_buffer (
literal|"---------------------\n\n"
argument|); 		  if (exec_keys&& exec_keys[
literal|0
argument|]) 		      printf_to_message_buffer 			(_(
literal|"The following commands can only be invoked via %s:\n\n"
argument|), exec_keys); 		  else 		      printf_to_message_buffer 			(_(
literal|"The following commands cannot be invoked at all:\n\n"
argument|));                   printed_one_mx =
literal|1
argument|;                 }                printf_to_message_buffer                 (
literal|"%s %s\n     %s\n"
argument|, 		 exec_keys,                  function_doc_array[i].func_name,                  replace_in_documentation (strlen (function_doc_array[i].doc) 					   ? _(function_doc_array[i].doc) 					   :
literal|""
argument|) 		);              }         }        if (printed_one_mx)         printf_to_message_buffer (
literal|"\n"
argument|);        maybe_free (exec_keys);
endif|#
directive|endif
comment|/* NAMED_FUNCTIONS */
argument|printf_to_message_buffer         (
literal|"%s"
argument|, replace_in_documentation          (_(
literal|"--- Use `\\[history-node]' or `\\[kill-node]' to exit ---\n"
argument|)));       node = message_buffer_to_node ();       internal_info_help_node_contents = node->contents;     }   else     {
comment|/* We already had the right contents, so simply use them. */
argument|node = build_message_node (
literal|""
argument|,
literal|0
argument|,
literal|0
argument|);       free (node->contents);       node->contents = contents;       node->nodelen =
literal|1
argument|+ strlen (contents);     }    internal_info_help_node = node;
comment|/* Do not GC this node's contents.  It never changes, and we never need      to delete it once it is made.  If you change some things (such as      placing information about dynamic variables in the help text) then      you will need to allow the contents to be gc'd, and you will have to      arrange to always regenerate the help node. */
if|#
directive|if
name|defined
argument_list|(
name|HELP_NODE_GETS_REGENERATED
argument_list|)
argument|add_gcable_pointer (internal_info_help_node->contents);
endif|#
directive|endif
argument|name_internal_node (internal_info_help_node, info_help_nodename);
comment|/* Even though this is an internal node, we don't want the window      system to treat it specially.  So we turn off the internalness      of it here. */
argument|internal_info_help_node->flags&= ~N_IsInternal; }
comment|/* Return a window which is the window showing help in this Info. */
comment|/* If the eligible window's height is>= this, split it to make the help    window.  Otherwise display the help window in the current window.  */
define|#
directive|define
name|HELP_SPLIT_SIZE
value|24
argument|static WINDOW * info_find_or_create_help_window () {   int help_is_only_window_p;   WINDOW *eligible = NULL;   WINDOW *help_window = get_window_of_node (internal_info_help_node);
comment|/* If we couldn't find the help window, then make it. */
argument|if (!help_window)     {       WINDOW *window;       int max =
literal|0
argument|;        for (window = windows; window; window = window->next)         {           if (window->height> max)             {               max = window->height;               eligible = window;             }         }        if (!eligible)         return NULL;     }
ifndef|#
directive|ifndef
name|HELP_NODE_GETS_REGENERATED
argument|else
comment|/* help window is static, just return it.  */
argument|return help_window;
endif|#
directive|endif
comment|/* not HELP_NODE_GETS_REGENERATED */
comment|/* Make sure that we have a node containing the help text.  The      argument is false if help will be the only window (so l must be used      to quit help), true if help will be one of several visible windows      (so CTRL-x 0 must be used to quit help).  */
argument|help_is_only_window_p      = (help_window&& !windows->next         || !help_window&& eligible->height< HELP_SPLIT_SIZE);   create_internal_info_help_node (help_is_only_window_p);
comment|/* Either use the existing window to display the help node, or create      a new window if there was no existing help window. */
argument|if (!help_window)     {
comment|/* Split the largest window into 2 windows, and show the help text          in that window. */
argument|if (eligible->height>= HELP_SPLIT_SIZE)         {           active_window = eligible;           help_window = window_make_window (internal_info_help_node);         }       else         {           set_remembered_pagetop_and_point (active_window);           window_set_node_of_window (active_window, internal_info_help_node);           help_window = active_window;         }     }   else     {
comment|/* Case where help node always gets regenerated, and we have an          existing window in which to place the node. */
argument|if (active_window != help_window)         {           set_remembered_pagetop_and_point (active_window);           active_window = help_window;         }       window_set_node_of_window (active_window, internal_info_help_node);     }   remember_window_and_node (help_window, help_window->node);   return help_window; }
comment|/* Create or move to the help window. */
argument|DECLARE_INFO_COMMAND (info_get_help_window, _(
literal|"Display help message"
argument|)) {   WINDOW *help_window;    help_window = info_find_or_create_help_window ();   if (help_window)     {       active_window = help_window;       active_window->flags |= W_UpdateWindow;     }   else     {       info_error (msg_cant_make_help);     } }
comment|/* Show the Info help node.  This means that the "info" file is installed    where it can easily be found on your system. */
argument|DECLARE_INFO_COMMAND (info_get_info_help_node, _(
literal|"Visit Info node `(info)Help'"
argument|)) {   NODE *node;   char *nodename;
comment|/* If there is a window on the screen showing the node "(info)Help" or      the node "(info)Help-Small-Screen", simply select that window. */
argument|{     WINDOW *win;      for (win = windows; win; win = win->next)       {         if (win->node&& win->node->filename&&             (strcasecmp              (filename_non_directory (win->node->filename),
literal|"info"
argument|) ==
literal|0
argument|)&&             ((strcmp (win->node->nodename,
literal|"Help"
argument|) ==
literal|0
argument|) ||              (strcmp (win->node->nodename,
literal|"Help-Small-Screen"
argument|) ==
literal|0
argument|)))           {             active_window = win;             return;           }       }   }
comment|/* If the current window is small, show the small screen help. */
argument|if (active_window->height<
literal|24
argument|)     nodename =
literal|"Help-Small-Screen"
argument|;   else     nodename =
literal|"Help"
argument|;
comment|/* Try to get the info file for Info. */
argument|node = info_get_node (
literal|"Info"
argument|, nodename);    if (!node)     {       if (info_recent_file_error)         info_error (info_recent_file_error);       else         info_error (msg_cant_file_node,
literal|"Info"
argument|, nodename);     }   else     {
comment|/* If the current window is very large (greater than 45 lines),          then split it and show the help node in another window.          Otherwise, use the current window. */
argument|if (active_window->height>
literal|45
argument|)         active_window = window_make_window (node);       else         {           set_remembered_pagetop_and_point (active_window);           window_set_node_of_window (active_window, node);         }        remember_window_and_node (active_window, node);     } }
comment|/* **************************************************************** */
comment|/*                                                                  */
comment|/*                   Groveling Info Keymaps and Docs                */
comment|/*                                                                  */
comment|/* **************************************************************** */
comment|/* Return the documentation associated with the Info command FUNCTION. */
argument|char * function_documentation (cmd)      InfoCommand *cmd; {   char *doc;
if|#
directive|if
name|defined
argument_list|(
name|INFOKEY
argument_list|)
argument|doc = cmd->doc;
else|#
directive|else
comment|/* !INFOKEY */
argument|register int i;    for (i =
literal|0
argument|; function_doc_array[i].func; i++)     if (InfoFunction(cmd) == function_doc_array[i].func)       break;    doc = function_doc_array[i].func ? function_doc_array[i].doc :
literal|""
argument|;
endif|#
directive|endif
comment|/* !INFOKEY */
argument|return replace_in_documentation ((strlen (doc) ==
literal|0
argument|) ? doc : _(doc)); }
if|#
directive|if
name|defined
argument_list|(
name|NAMED_FUNCTIONS
argument_list|)
comment|/* Return the user-visible name of the function associated with the    Info command FUNCTION. */
argument|char * function_name (cmd)      InfoCommand *cmd; {
if|#
directive|if
name|defined
argument_list|(
name|INFOKEY
argument_list|)
argument|return cmd->func_name;
else|#
directive|else
comment|/* !INFOKEY */
argument|register int i;    for (i =
literal|0
argument|; function_doc_array[i].func; i++)     if (InfoFunction(cmd) == function_doc_array[i].func)       break;    return (function_doc_array[i].func_name);
endif|#
directive|endif
comment|/* !INFOKEY */
argument|}
comment|/* Return a pointer to the info command for function NAME. */
argument|InfoCommand * named_function (name)      char *name; {   register int i;    for (i =
literal|0
argument|; function_doc_array[i].func; i++)     if (strcmp (function_doc_array[i].func_name, name) ==
literal|0
argument|)       break;    return (DocInfoCmd(&function_doc_array[i])); }
endif|#
directive|endif
comment|/* NAMED_FUNCTIONS */
comment|/* Return the documentation associated with KEY in MAP. */
argument|char * key_documentation (key, map)      char key;      Keymap map; {   InfoCommand *function = map[key].function;    if (function)     return (function_documentation (function));   else     return ((char *)NULL); }  DECLARE_INFO_COMMAND (describe_key, _(
literal|"Print documentation for KEY"
argument|)) {   char keys[
literal|50
argument|];   unsigned char keystroke;   char *k = keys;   Keymap map;    *k =
literal|'\0'
argument|;   map = window->keymap;    for (;;)     {       message_in_echo_area (_(
literal|"Describe key: %s"
argument|), pretty_keyseq (keys));       keystroke = info_get_input_char ();       unmessage_in_echo_area ();
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INFOKEY
argument_list|)
argument|if (Meta_p (keystroke))         {           if (map[ESC].type != ISKMAP)             {               window_message_in_echo_area               (_(
literal|"ESC %s is undefined."
argument|), pretty_keyname (UnMeta (keystroke)));               return;             }  	  *k++ =
literal|'\e'
argument|;           keystroke = UnMeta (keystroke);           map = (Keymap)map[ESC].function;         }
endif|#
directive|endif
comment|/* !INFOKEY */
comment|/* Add the KEYSTROKE to our list. */
argument|*k++ = keystroke;       *k =
literal|'\0'
argument|;        if (map[keystroke].function == (InfoCommand *)NULL)         {           message_in_echo_area (_(
literal|"%s is undefined."
argument|), pretty_keyseq (keys));           return;         }       else if (map[keystroke].type == ISKMAP)         {           map = (Keymap)map[keystroke].function;           continue;         }       else         {           char *keyname
argument_list|,
argument|*message
argument_list|,
argument|*fundoc
argument_list|,
argument|*funname =
literal|""
argument|;
if|#
directive|if
name|defined
argument_list|(
name|INFOKEY
argument_list|)
comment|/* If the key is bound to do-lowercase-version, but its 	     lower-case variant is undefined, say that this key is 	     also undefined.  This is especially important for unbound 	     edit keys that emit an escape sequence: it's terribly 	     confusing to see a message "Home (do-lowercase-version)" 	     or some such when Home is unbound.  */
argument|if (InfoFunction(map[keystroke].function) == info_do_lowercase_version) 	    { 	      unsigned char lowerkey = Meta_p(keystroke) 				       ? Meta (tolower (UnMeta (keystroke))) 				       : tolower (keystroke);  	      if (map[lowerkey].function == (InfoCommand *)NULL) 		{ 		  message_in_echo_area (_(
literal|"%s is undefined."
argument|), 					pretty_keyseq (keys)); 		  return; 		} 	    }
endif|#
directive|endif
argument|keyname = pretty_keyseq (keys);
if|#
directive|if
name|defined
argument_list|(
name|NAMED_FUNCTIONS
argument_list|)
argument|funname = function_name (map[keystroke].function);
endif|#
directive|endif
comment|/* NAMED_FUNCTIONS */
argument|fundoc = function_documentation (map[keystroke].function);            message = (char *)xmalloc             (
literal|10
argument|+ strlen (keyname) + strlen (fundoc) + strlen (funname));
if|#
directive|if
name|defined
argument_list|(
name|NAMED_FUNCTIONS
argument_list|)
argument|sprintf (message,
literal|"%s (%s): %s."
argument|, keyname, funname, fundoc);
else|#
directive|else
argument|sprintf (message, _(
literal|"%s is defined to %s."
argument|), keyname, fundoc);
endif|#
directive|endif
comment|/* !NAMED_FUNCTIONS */
argument|window_message_in_echo_area (
literal|"%s"
argument|, message);           free (message);           break;         }     } }
comment|/* Return the pretty printable name of a single character. */
argument|char * pretty_keyname (key)      unsigned char key; {   static char rep_buffer[
literal|30
argument|];   char *rep;    if (Meta_p (key))     {       char temp[
literal|20
argument|];        rep = pretty_keyname (UnMeta (key));
if|#
directive|if
name|defined
argument_list|(
name|INFOKEY
argument_list|)
argument|sprintf (temp,
literal|"M-%s"
argument|, rep);
else|#
directive|else
comment|/* !INFOKEY */
argument|sprintf (temp,
literal|"ESC %s"
argument|, rep);
endif|#
directive|endif
comment|/* !INFOKEY */
argument|strcpy (rep_buffer, temp);       rep = rep_buffer;     }   else if (Control_p (key))     {       switch (key)         {         case
literal|'\n'
argument|: rep =
literal|"LFD"
argument|; break;         case
literal|'\t'
argument|: rep =
literal|"TAB"
argument|; break;         case
literal|'\r'
argument|: rep =
literal|"RET"
argument|; break;         case ESC:  rep =
literal|"ESC"
argument|; break;          default:           sprintf (rep_buffer,
literal|"C-%c"
argument|, UnControl (key));           rep = rep_buffer;         }     }   else     {       switch (key)         {         case
literal|' '
argument|: rep =
literal|"SPC"
argument|; break;         case DEL: rep =
literal|"DEL"
argument|; break;         default:           rep_buffer[
literal|0
argument|] = key;           rep_buffer[
literal|1
argument|] =
literal|'\0'
argument|;           rep = rep_buffer;         }     }   return (rep); }
comment|/* Return the pretty printable string which represents KEYSEQ. */
argument|static void pretty_keyseq_internal ();  char * pretty_keyseq (keyseq)      char *keyseq; {   static char keyseq_rep[
literal|200
argument|];    keyseq_rep[
literal|0
argument|] =
literal|'\0'
argument|;   if (*keyseq)     pretty_keyseq_internal (keyseq, keyseq_rep);   return (keyseq_rep); }  static void pretty_keyseq_internal (keyseq, rep)      char *keyseq
argument_list|,
argument|*rep; {   if (term_kP&& strncmp(keyseq, term_kP, strlen(term_kP)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"PgUp"
argument|);       keyseq += strlen(term_kP);     }   else if (term_kN&& strncmp(keyseq, term_kN, strlen(term_kN)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"PgDn"
argument|);       keyseq += strlen(term_kN);     }
if|#
directive|if
name|defined
argument_list|(
name|INFOKEY
argument_list|)
argument|else if (term_kh&& strncmp(keyseq, term_kh, strlen(term_kh)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"Home"
argument|);       keyseq += strlen(term_kh);     }   else if (term_ke&& strncmp(keyseq, term_ke, strlen(term_ke)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"End"
argument|);       keyseq += strlen(term_ke);     }   else if (term_ki&& strncmp(keyseq, term_ki, strlen(term_ki)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"INS"
argument|);       keyseq += strlen(term_ki);     }   else if (term_kx&& strncmp(keyseq, term_kx, strlen(term_kx)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"DEL"
argument|);       keyseq += strlen(term_kx);     }
endif|#
directive|endif
comment|/* INFOKEY */
argument|else if (term_ku&& strncmp(keyseq, term_ku, strlen(term_ku)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"Up"
argument|);       keyseq += strlen(term_ku);     }   else if (term_kd&& strncmp(keyseq, term_kd, strlen(term_kd)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"Down"
argument|);       keyseq += strlen(term_kd);     }   else if (term_kl&& strncmp(keyseq, term_kl, strlen(term_kl)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"Left"
argument|);       keyseq += strlen(term_kl);     }   else if (term_kr&& strncmp(keyseq, term_kr, strlen(term_kr)) ==
literal|0
argument|)     {       strcpy(rep,
literal|"Right"
argument|);       keyseq += strlen(term_kr);     }   else     {       strcpy (rep, pretty_keyname (keyseq[
literal|0
argument|]));       keyseq++;     }   if (*keyseq)     {       strcat (rep,
literal|" "
argument|);       pretty_keyseq_internal (keyseq, rep + strlen(rep));     } }
comment|/* Return a pointer to the last character in s that is found in f. */
argument|static char * strrpbrk (s, f)      const char *s
argument_list|,
argument|*f; {   register const char *e = s + strlen(s);   register const char *t;    while (e-- != s)     {       for (t = f; *t; t++)         if (*e == *t) 	  return (char *)e;     }   return NULL; }
comment|/* Replace the names of functions with the key that invokes them. */
argument|char * replace_in_documentation (string, help_is_only_window_p)      char *string;      int help_is_only_window_p; {   unsigned reslen = strlen (string);   register int i
argument_list|,
argument|start
argument_list|,
argument|next;   static char *result = (char *)NULL;    maybe_free (result);   result = (char *)xmalloc (
literal|1
argument|+ reslen);    i = next = start =
literal|0
argument|;
comment|/* Skip to the beginning of a replaceable function. */
argument|for (i = start; string[i]; i++)     {       int j = i +
literal|1
argument|;
comment|/* Is this the start of a replaceable function name? */
argument|if (string[i] ==
literal|'\\'
argument|)       	{ 	  char *fmt = NULL; 	  unsigned min =
literal|0
argument|; 	  unsigned max =
literal|0
argument|;  	  if(string[j] ==
literal|'%'
argument|) 	    { 	      if (string[++j] ==
literal|'-'
argument|) 		j++; 	      if (isdigit(string[j])) 		{ 		  min = atoi(string + j); 		  while (isdigit(string[j])) 		    j++; 		  if (string[j] ==
literal|'.'
argument|&& isdigit(string[j +
literal|1
argument|])) 		    { 		      j +=
literal|1
argument|; 		      max = atoi(string + j); 		      while (isdigit(string[j])) 			j++; 		    } 		  fmt = (char *)xmalloc (j - i +
literal|2
argument|); 		  strncpy (fmt, string + i +
literal|1
argument|, j - i); 		  fmt[j - i -
literal|1
argument|] =
literal|'s'
argument|; 		  fmt[j - i] =
literal|'\0'
argument|; 		} 	      else 		j = i +
literal|1
argument|; 	    } 	  if (string[j] ==
literal|'['
argument|) 	    { 	      unsigned arg =
literal|0
argument|; 	      char *argstr = NULL; 	      char *rep_name
argument_list|,
argument|*fun_name
argument_list|,
argument|*rep; 	      InfoCommand *command; 	      char *repstr = NULL; 	      unsigned replen;
comment|/* Copy in the old text. */
argument|strncpy (result + next, string + start, i - start); 	      next += (i - start); 	      start = j +
literal|1
argument|;
comment|/* Look for an optional numeric arg. */
argument|i = start; 	      if (isdigit(string[i]) 		  || (string[i] ==
literal|'-'
argument|&& isdigit(string[i +
literal|1
argument|])) ) 		{ 		  arg = atoi(string + i); 		  if (string[i] ==
literal|'-'
argument|) 		    i++; 		  while (isdigit(string[i])) 		    i++; 		} 	      start = i;
comment|/* Move to the end of the function name. */
argument|for (i = start; string[i]&& (string[i] !=
literal|']'
argument|); i++);  	      rep_name = (char *)xmalloc (
literal|1
argument|+ i - start); 	      strncpy (rep_name, string + start, i - start); 	      rep_name[i - start] =
literal|'\0'
argument|;
comment|/* If we have only one window (because the window size was too 	       small to split it), we have to quit help by going back one 	       noew in the history list, not deleting the window.  */
argument|if (strcmp (rep_name,
literal|"quit-help"
argument|) ==
literal|0
argument|) 		fun_name = help_is_only_window_p ?
literal|"history-node"
argument|:
literal|"delete-window"
argument|; 	      else 	        fun_name = rep_name;
comment|/* Find a key which invokes this function in the info_keymap. */
argument|command = named_function (fun_name);  	      free (rep_name);
comment|/* If the internal documentation string fails, there is a 		 serious problem with the associated command's documentation. 		 We croak so that it can be fixed immediately. */
argument|if (!command) 		abort ();  	      if (arg) 	      	{ 		  char *argrep
argument_list|,
argument|*p;  		  argrep = where_is (info_keymap, InfoCmd(info_add_digit_to_numeric_arg)); 		  p = argrep ? strrpbrk (argrep,
literal|"0123456789-"
argument|) : NULL; 		  if (p) 		    { 		      argstr = (char *)xmalloc (p - argrep +
literal|21
argument|); 		      strncpy (argstr, argrep, p - argrep); 		      sprintf (argstr + (p - argrep),
literal|"%d"
argument|, arg); 		    } 		  else 		    command = NULL; 		} 	      rep = command ? where_is (info_keymap, command) : NULL; 	      if (!rep) 	        rep =
literal|"N/A"
argument|; 	      replen = (argstr ? strlen (argstr) +
literal|1
argument|:
literal|0
argument|) + strlen (rep); 	      repstr = (char *)xmalloc (replen); 	      repstr[
literal|0
argument|] =
literal|'\0'
argument|; 	      if (argstr) 		{ 		  strcat(repstr, argstr); 		  strcat(repstr,
literal|" "
argument|); 		  free (argstr); 		} 	      strcat(repstr, rep);  	      if (fmt) 		{ 		  if (replen> max) 		    replen = max; 		  if (replen< min) 		    replen = min; 		} 	      if (next + replen> reslen) 		{ 		  reslen = next + replen +
literal|1
argument|; 		  result = (char *)xrealloc (result, reslen +
literal|1
argument|); 		}  	      if (fmt) 		  sprintf (result + next, fmt, repstr); 	      else 		  strcpy (result + next, repstr);  	      next = strlen (result); 	      free (repstr);  	      start = i; 	      if (string[i]) 		start++; 	    }  	  maybe_free (fmt); 	}     }   strcpy (result + next, string + start);   return (result); }
comment|/* Return a string of characters which could be typed from the keymap    MAP to invoke FUNCTION. */
argument|static char *where_is_rep = (char *)NULL; static int where_is_rep_index =
literal|0
argument|; static int where_is_rep_size =
literal|0
argument|;  char * where_is (map, cmd)      Keymap map;      InfoCommand *cmd; {   char *rep;    if (!where_is_rep_size)     where_is_rep = (char *)xmalloc (where_is_rep_size =
literal|100
argument|);   where_is_rep_index =
literal|0
argument|;    rep = where_is_internal (map, cmd);
comment|/* If it couldn't be found, return "M-x Foo" (or equivalent). */
argument|if (!rep)     {       char *name;        name = function_name (cmd);       if (!name)       	return NULL;
comment|/* no such function */
argument|rep = where_is_internal (map, InfoCmd(info_execute_command));       if (!rep)         return
literal|""
argument|;
comment|/* function exists but can't be got to by user */
argument|sprintf (where_is_rep,
literal|"%s %s"
argument|, rep, name);        rep = where_is_rep;     }   return (rep); }
comment|/* Return the printed rep of the keystrokes that invoke FUNCTION,    as found in MAP, or NULL. */
argument|static char * where_is_internal (map, cmd)      Keymap map;      InfoCommand *cmd; {
if|#
directive|if
name|defined
argument_list|(
name|INFOKEY
argument_list|)
argument|register FUNCTION_KEYSEQ *k;    for (k = cmd->keys; k; k = k->next)     if (k->map == map)       return pretty_keyseq (k->keyseq);    return NULL;
else|#
directive|else
comment|/* !INFOKEY */
argument|register int i;
comment|/* If the function is directly invokable in MAP, return the representation      of that keystroke. */
argument|for (i =
literal|0
argument|; i<
literal|256
argument|; i++)     if ((map[i].type == ISFUNC)&& map[i].function == cmd)       {         sprintf (where_is_rep + where_is_rep_index,
literal|"%s"
argument|, pretty_keyname (i));         return (where_is_rep);       }
comment|/* Okay, search subsequent maps for this function. */
argument|for (i =
literal|0
argument|; i<
literal|256
argument|; i++)     {       if (map[i].type == ISKMAP)         {           int saved_index = where_is_rep_index;           char *rep;            sprintf (where_is_rep + where_is_rep_index,
literal|"%s "
argument|,                    pretty_keyname (i));            where_is_rep_index = strlen (where_is_rep);           rep = where_is_internal ((Keymap)map[i].function, cmd);            if (rep)             return (where_is_rep);            where_is_rep_index = saved_index;         }     }    return NULL;
endif|#
directive|endif
comment|/* INFOKEY */
argument|}  extern char *read_function_name ();  DECLARE_INFO_COMMAND (info_where_is,    _(
literal|"Show what to type to execute a given command"
argument|)) {   char *command_name;    command_name = read_function_name (_(
literal|"Where is command: "
argument|), window);    if (!command_name)     {       info_abort_key (active_window, count, key);       return;     }    if (*command_name)     {       InfoCommand *command;        command = named_function (command_name);        if (command)         {           char *location;            location = where_is (active_window->keymap, command);            if (!location || !location[
literal|0
argument|])             {               info_error (_(
literal|"`%s' is not on any keys"
argument|), command_name);             }           else             {               if (strstr (location, function_name (command)))                 window_message_in_echo_area                   (_(
literal|"%s can only be invoked via %s."
argument|), command_name, location);               else                 window_message_in_echo_area                   (_(
literal|"%s can be invoked via %s."
argument|), command_name, location);             }         }       else         info_error (_(
literal|"There is no function named `%s'"
argument|), command_name);     }    free (command_name); }
end_decl_stmt

end_unit


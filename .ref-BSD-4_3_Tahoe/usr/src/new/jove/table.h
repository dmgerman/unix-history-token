begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|struct
name|word
name|Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|table
name|Table
typedef|;
end_typedef

begin_struct
struct|struct
name|word
block|{
name|Word
modifier|*
name|wd_next
decl_stmt|;
name|char
modifier|*
name|wd_text
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|table
block|{
name|Table
modifier|*
name|t_next
decl_stmt|;
name|Word
modifier|*
name|t_wordlist
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|Table
modifier|*
name|make_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Word
modifier|*
name|word_in_table
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|table_top
parameter_list|(
name|table
parameter_list|)
value|(table->t_wordlist)
end_define

begin_define
define|#
directive|define
name|next_word
parameter_list|(
name|w
parameter_list|)
value|(w->wd_next)
end_define

begin_define
define|#
directive|define
name|last_word_p
parameter_list|(
name|w
parameter_list|)
value|(w->wd_next == NIL)
end_define

begin_define
define|#
directive|define
name|word_text
parameter_list|(
name|w
parameter_list|)
value|(w->wd_text)
end_define

begin_define
define|#
directive|define
name|word_length
parameter_list|(
name|w
parameter_list|)
value|(strlen(word_text(w)))
end_define

end_unit


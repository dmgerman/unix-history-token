begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|RCSIDENT
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAINLINE
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|zzdumpid
index|[]
init|=
literal|"$Header: dump.h,v 1.7 85/01/18 15:47:35 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(RCSIDENT)&& defined(MAINLINE)
end_endif

begin_struct
struct|struct
name|dump_f
comment|/* variable relations */
block|{
name|char
modifier|*
name|du_name
decl_stmt|;
name|int
name|du_number
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Variable numbers for the assorted fields of the  *	notesfile descriptor.  */
end_comment

begin_define
define|#
directive|define
name|NF_TITLE
value|1
end_define

begin_define
define|#
directive|define
name|NF_DIRECTOR_MESSAGE
value|2
end_define

begin_define
define|#
directive|define
name|NF_LAST_MODIFIED
value|3
end_define

begin_define
define|#
directive|define
name|NF_STATUS
value|4
end_define

begin_define
define|#
directive|define
name|NF_ID_SEQUENCE
value|5
end_define

begin_define
define|#
directive|define
name|NF_NUMBER
value|6
end_define

begin_define
define|#
directive|define
name|NF_LAST_TRANSMIT
value|7
end_define

begin_define
define|#
directive|define
name|NF_CREATED
value|8
end_define

begin_define
define|#
directive|define
name|NF_LAST_USED
value|9
end_define

begin_define
define|#
directive|define
name|NF_DAYS_USED
value|10
end_define

begin_define
define|#
directive|define
name|NF_NOTES_WRITTEN
value|11
end_define

begin_define
define|#
directive|define
name|NF_NOTES_READ
value|12
end_define

begin_define
define|#
directive|define
name|NF_NOTES_TRANSMITTED
value|13
end_define

begin_define
define|#
directive|define
name|NF_NOTES_RECEIVED
value|14
end_define

begin_define
define|#
directive|define
name|NF_NOTES_DROPPED
value|15
end_define

begin_define
define|#
directive|define
name|NF_RESPONSES_WRITTEN
value|16
end_define

begin_define
define|#
directive|define
name|NF_RESPONSES_READ
value|17
end_define

begin_define
define|#
directive|define
name|NF_RESPONSES_TRANSMITTED
value|18
end_define

begin_define
define|#
directive|define
name|NF_RESPONSES_RECEIVED
value|19
end_define

begin_define
define|#
directive|define
name|NF_RESPONSES_DROPPED
value|20
end_define

begin_define
define|#
directive|define
name|NF_ENTRIES
value|21
end_define

begin_define
define|#
directive|define
name|NF_WALLTIME
value|22
end_define

begin_define
define|#
directive|define
name|NF_ORPHANS_RECEIVED
value|23
end_define

begin_define
define|#
directive|define
name|NF_ORPHANS_ADOPTED
value|24
end_define

begin_define
define|#
directive|define
name|NF_TRANSMITS
value|25
end_define

begin_define
define|#
directive|define
name|NF_RECEIVES
value|26
end_define

begin_define
define|#
directive|define
name|NF_EXPIRATION_AGE
value|27
end_define

begin_define
define|#
directive|define
name|NF_EXPIRATION_ACTION
value|28
end_define

begin_define
define|#
directive|define
name|NF_EXPIRATION_STATUS
value|29
end_define

begin_define
define|#
directive|define
name|NF_WORKING_SET_SIZE
value|30
end_define

begin_define
define|#
directive|define
name|NF_LONGEST_TEXT
value|31
end_define

begin_define
define|#
directive|define
name|NF_POLICY_EXISTS
value|32
end_define

begin_define
define|#
directive|define
name|NF_DESCRIPTOR
value|33
end_define

begin_comment
comment|/*  *	Variable numbers for the assorted fields of the  *	Access list  *  *	Currently unused, but what the hell.  */
end_comment

begin_define
define|#
directive|define
name|ACCESS_RIGHT
value|1
end_define

begin_define
define|#
directive|define
name|ACCESS_FINISHED
value|2
end_define

begin_comment
comment|/*  *	RFC-style lines for a note  */
end_comment

begin_define
define|#
directive|define
name|NOTE_TITLE
value|1
end_define

begin_define
define|#
directive|define
name|NOTE_AUTHOR
value|2
end_define

begin_define
define|#
directive|define
name|NOTE_AUTHOR_UID
value|3
end_define

begin_define
define|#
directive|define
name|NOTE_ID
value|4
end_define

begin_define
define|#
directive|define
name|NOTE_WRITTEN
value|5
end_define

begin_define
define|#
directive|define
name|NOTE_RECEIVED
value|6
end_define

begin_define
define|#
directive|define
name|NOTE_MODIFIED
value|7
end_define

begin_define
define|#
directive|define
name|NOTE_FROMSYS
value|8
end_define

begin_define
define|#
directive|define
name|NOTE_STATUS
value|9
end_define

begin_define
define|#
directive|define
name|NOTE_LENGTH
value|10
end_define

begin_comment
comment|/*  *	RFC-style lines for a response  */
end_comment

begin_define
define|#
directive|define
name|RESP_TITLE
value|1
end_define

begin_define
define|#
directive|define
name|RESP_PARENT
value|2
end_define

begin_define
define|#
directive|define
name|RESP_AUTHOR
value|3
end_define

begin_define
define|#
directive|define
name|RESP_AUTHOR_UID
value|4
end_define

begin_define
define|#
directive|define
name|RESP_ID
value|5
end_define

begin_define
define|#
directive|define
name|RESP_WRITTEN
value|6
end_define

begin_define
define|#
directive|define
name|RESP_RECEIVED
value|7
end_define

begin_define
define|#
directive|define
name|RESP_FROMSYS
value|8
end_define

begin_define
define|#
directive|define
name|RESP_STATUS
value|9
end_define

begin_define
define|#
directive|define
name|RESP_LENGTH
value|10
end_define

begin_comment
comment|/*  *	Declarations for assorted tables of variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dump_f
name|descrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dump_f
name|accessnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* access rights */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dump_f
name|notenames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a note */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dump_f
name|respnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a response */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: overview.h,v 3.0 1992/12/14 00:14:09 davison Trn $ */
end_comment

begin_comment
comment|/* The order of the overview file fields */
end_comment

begin_define
define|#
directive|define
name|OV_NUM
value|0
end_define

begin_define
define|#
directive|define
name|OV_SUBJ
value|1
end_define

begin_define
define|#
directive|define
name|OV_FROM
value|2
end_define

begin_define
define|#
directive|define
name|OV_DATE
value|3
end_define

begin_define
define|#
directive|define
name|OV_MSGID
value|4
end_define

begin_define
define|#
directive|define
name|OV_REFS
value|5
end_define

begin_define
define|#
directive|define
name|OV_BYTES
value|6
end_define

begin_define
define|#
directive|define
name|OV_LINES
value|7
end_define

begin_define
define|#
directive|define
name|OV_OTHERS
value|8
end_define

begin_comment
comment|/* this catch-all field must be last */
end_comment

begin_undef
undef|#
directive|undef
name|OV_OTHERS_HAS_XREFS
end_undef

begin_comment
comment|/* forces trn to assume xrefs always exist */
end_comment

begin_comment
comment|/* If all the overview files trn will be accessing have xrefs in the OTHERS ** field you may choose to define OV_OTHERS_HAS_XREFS.  This may save some ** article accessing during the time that it would take trn to determine ** this for itself. */
end_comment

begin_comment
comment|/* NOTE that you must NOT define OV_XREFS unless you have opted to create ** a new (non-standard) overview field for xrefs instead of placing them ** in the OTHERS field.  If you have included the xrefs header without its ** prefix into a field of its own, define OV_XREFS with the appropriate ** field number in the list above.  If it has the "Xrefs:" prefix, just ** point the OV_OTHERS field at it.  Alternately, you can define both ** OV_XREFS and OV_LAX_XREFS and trn accepts a field with or without ** the "Xrefs:" prefix. */
end_comment

begin_undef
undef|#
directive|undef
name|OV_XREFS
end_undef

begin_comment
comment|/* only define when using non-standard .overview */
end_comment

begin_undef
undef|#
directive|undef
name|OV_LAX_XREFS
end_undef

begin_comment
comment|/* allow xrefs field to have a header-prefix */
end_comment

begin_comment
comment|/* What name to append to the directory name to read an overview file. ** This REQUIRES a leading slash unless you're getting fancy. */
end_comment

begin_define
define|#
directive|define
name|OV_FILE_NAME
value|"/.overview"
end_define

begin_comment
comment|/* How many overview lines to read with one NNTP call */
end_comment

begin_define
define|#
directive|define
name|OV_CHUNK_SIZE
value|100
end_define

end_unit


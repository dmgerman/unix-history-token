begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * DviChar.h  *  * descriptions for mapping dvi names to  * font indexes and back.  Dvi fonts are all  * 256 elements (actually only 256-32 are usable).  *  * The encoding names are taken from X -  * case insensitive, a dash separating the  * CharSetRegistry from the CharSetEncoding  */
end_comment

begin_define
define|#
directive|define
name|DVI_MAX_SYNONYMS
value|10
end_define

begin_define
define|#
directive|define
name|DVI_MAP_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|DVI_HASH_SIZE
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|_dviCharNameHash
block|{
name|struct
name|_dviCharNameHash
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|position
decl_stmt|;
block|}
name|DviCharNameHash
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dviCharNameMap
block|{
name|char
modifier|*
name|encoding
decl_stmt|;
name|int
name|special
decl_stmt|;
name|char
modifier|*
name|dvi_names
index|[
name|DVI_MAP_SIZE
index|]
index|[
name|DVI_MAX_SYNONYMS
index|]
decl_stmt|;
name|DviCharNameHash
modifier|*
name|buckets
index|[
name|DVI_HASH_SIZE
index|]
decl_stmt|;
block|}
name|DviCharNameMap
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|DviCharNameMap
modifier|*
name|DviFindMap
parameter_list|(
comment|/* char *encoding */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DviRegisterMap
parameter_list|(
comment|/* DviCharNameMap *map */
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOTDEF
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|DviCharName
parameter_list|(
comment|/* DviCharNameMap *map, int index, int synonym */
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DviCharName
parameter_list|(
name|map
parameter_list|,
name|index
parameter_list|,
name|synonym
parameter_list|)
value|((map)->dvi_names[index][synonym])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|DviCharIndex
parameter_list|(
comment|/* DviCharNameMap *map, char *name */
parameter_list|)
function_decl|;
end_function_decl

end_unit


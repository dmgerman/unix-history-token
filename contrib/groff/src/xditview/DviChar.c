begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * DviChar.c  *  * Map DVI (ditroff output) character names to  * font indexes and back  */
end_comment

begin_include
include|#
directive|include
file|"DviChar.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|allocHash
parameter_list|()
value|((DviCharNameHash *) xmalloc (sizeof (DviCharNameHash)))
end_define

begin_struct
struct|struct
name|map_list
block|{
name|struct
name|map_list
modifier|*
name|next
decl_stmt|;
name|DviCharNameMap
modifier|*
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|map_list
modifier|*
name|world
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|standard_maps_loaded
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|load_standard_maps
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|hash_name
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|dispose_hash
argument_list|()
operator|,
name|compute_hash
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function
name|DviCharNameMap
modifier|*
name|DviFindMap
parameter_list|(
name|encoding
parameter_list|)
name|char
modifier|*
name|encoding
decl_stmt|;
block|{
name|struct
name|map_list
modifier|*
name|m
decl_stmt|;
if|if
condition|(
operator|!
name|standard_maps_loaded
condition|)
name|load_standard_maps
argument_list|()
expr_stmt|;
for|for
control|(
name|m
operator|=
name|world
init|;
name|m
condition|;
name|m
operator|=
name|m
operator|->
name|next
control|)
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|m
operator|->
name|map
operator|->
name|encoding
argument_list|,
name|encoding
argument_list|)
condition|)
return|return
name|m
operator|->
name|map
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|DviRegisterMap
parameter_list|(
name|map
parameter_list|)
name|DviCharNameMap
modifier|*
name|map
decl_stmt|;
block|{
name|struct
name|map_list
modifier|*
name|m
decl_stmt|;
if|if
condition|(
operator|!
name|standard_maps_loaded
condition|)
name|load_standard_maps
argument_list|()
expr_stmt|;
for|for
control|(
name|m
operator|=
name|world
init|;
name|m
condition|;
name|m
operator|=
name|m
operator|->
name|next
control|)
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|m
operator|->
name|map
operator|->
name|encoding
argument_list|,
name|map
operator|->
name|encoding
argument_list|)
condition|)
break|break;
if|if
condition|(
operator|!
name|m
condition|)
block|{
name|m
operator|=
operator|(
expr|struct
name|map_list
operator|*
operator|)
name|xmalloc
argument_list|(
sizeof|sizeof
expr|*
name|m
argument_list|)
expr_stmt|;
name|m
operator|->
name|next
operator|=
name|world
expr_stmt|;
name|world
operator|=
name|m
expr_stmt|;
block|}
name|dispose_hash
argument_list|(
name|map
argument_list|)
expr_stmt|;
name|m
operator|->
name|map
operator|=
name|map
expr_stmt|;
name|compute_hash
argument_list|(
name|map
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|dispose_hash
argument_list|(
argument|map
argument_list|)
name|DviCharNameMap
operator|*
name|map
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|DviCharNameHash
modifier|*
modifier|*
name|buckets
decl_stmt|;
name|DviCharNameHash
modifier|*
name|h
decl_stmt|,
modifier|*
name|next
decl_stmt|;
name|int
name|i
decl_stmt|;
name|buckets
operator|=
name|map
operator|->
name|buckets
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|DVI_HASH_SIZE
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|h
operator|=
name|buckets
index|[
name|i
index|]
init|;
name|h
condition|;
name|h
operator|=
name|next
control|)
block|{
name|next
operator|=
name|h
operator|->
name|next
expr_stmt|;
name|free
argument_list|(
name|h
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_function
specifier|static
name|int
name|hash_name
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|*
name|name
condition|)
name|i
operator|=
operator|(
name|i
operator|<<
literal|1
operator|)
operator|^
operator|*
name|name
operator|++
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
name|i
operator|=
operator|-
name|i
expr_stmt|;
return|return
name|i
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|compute_hash
argument_list|(
argument|map
argument_list|)
name|DviCharNameMap
operator|*
name|map
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|DviCharNameHash
modifier|*
modifier|*
name|buckets
decl_stmt|;
name|int
name|c
decl_stmt|,
name|s
decl_stmt|,
name|i
decl_stmt|;
name|DviCharNameHash
modifier|*
name|h
decl_stmt|;
name|buckets
operator|=
name|map
operator|->
name|buckets
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|DVI_HASH_SIZE
condition|;
name|i
operator|++
control|)
name|buckets
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
name|DVI_MAP_SIZE
condition|;
name|c
operator|++
control|)
for|for
control|(
name|s
operator|=
literal|0
init|;
name|s
operator|<
name|DVI_MAX_SYNONYMS
condition|;
name|s
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|map
operator|->
name|dvi_names
index|[
name|c
index|]
index|[
name|s
index|]
condition|)
break|break;
name|i
operator|=
name|hash_name
argument_list|(
name|map
operator|->
name|dvi_names
index|[
name|c
index|]
index|[
name|s
index|]
argument_list|)
operator|%
name|DVI_HASH_SIZE
expr_stmt|;
name|h
operator|=
name|allocHash
argument_list|()
expr_stmt|;
name|h
operator|->
name|next
operator|=
name|buckets
index|[
name|i
index|]
expr_stmt|;
name|buckets
index|[
name|i
index|]
operator|=
name|h
expr_stmt|;
name|h
operator|->
name|name
operator|=
name|map
operator|->
name|dvi_names
index|[
name|c
index|]
index|[
name|s
index|]
expr_stmt|;
name|h
operator|->
name|position
operator|=
name|c
expr_stmt|;
block|}
block|}
end_block

begin_function
name|int
name|DviCharIndex
parameter_list|(
name|map
parameter_list|,
name|name
parameter_list|)
name|DviCharNameMap
modifier|*
name|map
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|DviCharNameHash
modifier|*
name|h
decl_stmt|;
name|i
operator|=
name|hash_name
argument_list|(
name|name
argument_list|)
operator|%
name|DVI_HASH_SIZE
expr_stmt|;
for|for
control|(
name|h
operator|=
name|map
operator|->
name|buckets
index|[
name|i
index|]
init|;
name|h
condition|;
name|h
operator|=
name|h
operator|->
name|next
control|)
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|h
operator|->
name|name
argument_list|,
name|name
argument_list|)
condition|)
return|return
name|h
operator|->
name|position
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|DviCharNameMap
name|ISO8859_1_map
init|=
block|{
literal|"iso8859-1"
block|,
literal|0
block|,
block|{
block|{
literal|0
block|,
comment|/* 0 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 1 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 2 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 3 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 4 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 5 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 6 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 7 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 8 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 9 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 10 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 11 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 12 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 13 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 14 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 15 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 16 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 17 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 18 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 19 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 20 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 21 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 22 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 23 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 24 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 25 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 26 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 27 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 28 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 29 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 30 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 31 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 32 */
block|}
block|,
block|{
literal|"!"
block|,
comment|/* 33 */
block|}
block|,
block|{
literal|"\""
block|,
literal|"dq"
block|,
comment|/* 34 */
block|}
block|,
block|{
literal|"#"
block|,
literal|"sh"
block|,
comment|/* 35 */
block|}
block|,
block|{
literal|"$"
block|,
literal|"Do"
block|,
comment|/* 36 */
block|}
block|,
block|{
literal|"%"
block|,
comment|/* 37 */
block|}
block|,
block|{
literal|"&"
block|,
comment|/* 38 */
block|}
block|,
block|{
literal|"'"
block|,
literal|"cq"
block|,
comment|/* 39 */
block|}
block|,
block|{
literal|"("
block|,
comment|/* 40 */
block|}
block|,
block|{
literal|")"
block|,
comment|/* 41 */
block|}
block|,
block|{
literal|"*"
block|,
comment|/* 42 */
block|}
block|,
block|{
literal|"+"
block|,
comment|/* 43 */
block|}
block|,
block|{
literal|","
block|,
comment|/* 44 */
block|}
block|,
block|{
literal|"\\-"
block|,
comment|/* 45 */
block|}
block|,
block|{
literal|"."
block|,
comment|/* 46 */
block|}
block|,
block|{
literal|"/"
block|,
literal|"sl"
block|,
comment|/* 47 */
block|}
block|,
block|{
literal|"0"
block|,
comment|/* 48 */
block|}
block|,
block|{
literal|"1"
block|,
comment|/* 49 */
block|}
block|,
block|{
literal|"2"
block|,
comment|/* 50 */
block|}
block|,
block|{
literal|"3"
block|,
comment|/* 51 */
block|}
block|,
block|{
literal|"4"
block|,
comment|/* 52 */
block|}
block|,
block|{
literal|"5"
block|,
comment|/* 53 */
block|}
block|,
block|{
literal|"6"
block|,
comment|/* 54 */
block|}
block|,
block|{
literal|"7"
block|,
comment|/* 55 */
block|}
block|,
block|{
literal|"8"
block|,
comment|/* 56 */
block|}
block|,
block|{
literal|"9"
block|,
comment|/* 57 */
block|}
block|,
block|{
literal|":"
block|,
comment|/* 58 */
block|}
block|,
block|{
literal|";"
block|,
comment|/* 59 */
block|}
block|,
block|{
literal|"<"
block|,
comment|/* 60 */
block|}
block|,
block|{
literal|"="
block|,
literal|"eq"
block|,
comment|/* 61 */
block|}
block|,
block|{
literal|">"
block|,
comment|/* 62 */
block|}
block|,
block|{
literal|"?"
block|,
comment|/* 63 */
block|}
block|,
block|{
literal|"@"
block|,
literal|"at"
block|,
comment|/* 64 */
block|}
block|,
block|{
literal|"A"
block|,
comment|/* 65 */
block|}
block|,
block|{
literal|"B"
block|,
comment|/* 66 */
block|}
block|,
block|{
literal|"C"
block|,
comment|/* 67 */
block|}
block|,
block|{
literal|"D"
block|,
comment|/* 68 */
block|}
block|,
block|{
literal|"E"
block|,
comment|/* 69 */
block|}
block|,
block|{
literal|"F"
block|,
comment|/* 70 */
block|}
block|,
block|{
literal|"G"
block|,
comment|/* 71 */
block|}
block|,
block|{
literal|"H"
block|,
comment|/* 72 */
block|}
block|,
block|{
literal|"I"
block|,
comment|/* 73 */
block|}
block|,
block|{
literal|"J"
block|,
comment|/* 74 */
block|}
block|,
block|{
literal|"K"
block|,
comment|/* 75 */
block|}
block|,
block|{
literal|"L"
block|,
comment|/* 76 */
block|}
block|,
block|{
literal|"M"
block|,
comment|/* 77 */
block|}
block|,
block|{
literal|"N"
block|,
comment|/* 78 */
block|}
block|,
block|{
literal|"O"
block|,
comment|/* 79 */
block|}
block|,
block|{
literal|"P"
block|,
comment|/* 80 */
block|}
block|,
block|{
literal|"Q"
block|,
comment|/* 81 */
block|}
block|,
block|{
literal|"R"
block|,
comment|/* 82 */
block|}
block|,
block|{
literal|"S"
block|,
comment|/* 83 */
block|}
block|,
block|{
literal|"T"
block|,
comment|/* 84 */
block|}
block|,
block|{
literal|"U"
block|,
comment|/* 85 */
block|}
block|,
block|{
literal|"V"
block|,
comment|/* 86 */
block|}
block|,
block|{
literal|"W"
block|,
comment|/* 87 */
block|}
block|,
block|{
literal|"X"
block|,
comment|/* 88 */
block|}
block|,
block|{
literal|"Y"
block|,
comment|/* 89 */
block|}
block|,
block|{
literal|"Z"
block|,
comment|/* 90 */
block|}
block|,
block|{
literal|"["
block|,
literal|"lB"
block|,
comment|/* 91 */
block|}
block|,
block|{
literal|"\\"
block|,
literal|"rs"
block|,
comment|/* 92 */
block|}
block|,
block|{
literal|"]"
block|,
literal|"rB"
block|,
comment|/* 93 */
block|}
block|,
block|{
literal|"^"
block|,
literal|"a^"
block|,
literal|"ha"
comment|/* 94 */
block|}
block|,
block|{
literal|"_"
block|,
comment|/* 95 */
block|}
block|,
block|{
literal|"`"
block|,
literal|"oq"
block|,
comment|/* 96 */
block|}
block|,
block|{
literal|"a"
block|,
comment|/* 97 */
block|}
block|,
block|{
literal|"b"
block|,
comment|/* 98 */
block|}
block|,
block|{
literal|"c"
block|,
comment|/* 99 */
block|}
block|,
block|{
literal|"d"
block|,
comment|/* 100 */
block|}
block|,
block|{
literal|"e"
block|,
comment|/* 101 */
block|}
block|,
block|{
literal|"f"
block|,
comment|/* 102 */
block|}
block|,
block|{
literal|"g"
block|,
comment|/* 103 */
block|}
block|,
block|{
literal|"h"
block|,
comment|/* 104 */
block|}
block|,
block|{
literal|"i"
block|,
comment|/* 105 */
block|}
block|,
block|{
literal|"j"
block|,
comment|/* 106 */
block|}
block|,
block|{
literal|"k"
block|,
comment|/* 107 */
block|}
block|,
block|{
literal|"l"
block|,
comment|/* 108 */
block|}
block|,
block|{
literal|"m"
block|,
comment|/* 109 */
block|}
block|,
block|{
literal|"n"
block|,
comment|/* 110 */
block|}
block|,
block|{
literal|"o"
block|,
comment|/* 111 */
block|}
block|,
block|{
literal|"p"
block|,
comment|/* 112 */
block|}
block|,
block|{
literal|"q"
block|,
comment|/* 113 */
block|}
block|,
block|{
literal|"r"
block|,
comment|/* 114 */
block|}
block|,
block|{
literal|"s"
block|,
comment|/* 115 */
block|}
block|,
block|{
literal|"t"
block|,
comment|/* 116 */
block|}
block|,
block|{
literal|"u"
block|,
comment|/* 117 */
block|}
block|,
block|{
literal|"v"
block|,
comment|/* 118 */
block|}
block|,
block|{
literal|"w"
block|,
comment|/* 119 */
block|}
block|,
block|{
literal|"x"
block|,
comment|/* 120 */
block|}
block|,
block|{
literal|"y"
block|,
comment|/* 121 */
block|}
block|,
block|{
literal|"z"
block|,
comment|/* 122 */
block|}
block|,
block|{
literal|"{"
block|,
literal|"lC"
block|,
comment|/* 123 */
block|}
block|,
block|{
literal|"|"
block|,
literal|"or"
block|,
literal|"ba"
comment|/* 124 */
block|}
block|,
block|{
literal|"}"
block|,
literal|"rC"
block|,
comment|/* 125 */
block|}
block|,
block|{
literal|"~"
block|,
literal|"a~"
block|,
literal|"ap"
block|,
literal|"ti"
comment|/* 126 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 127 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 128 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 129 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 130 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 131 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 132 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 133 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 134 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 135 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 136 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 137 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 138 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 139 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 140 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 141 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 142 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 143 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 144 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 145 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 146 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 147 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 148 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 149 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 150 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 151 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 152 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 153 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 154 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 155 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 156 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 157 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 158 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 159 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 160 */
block|}
block|,
block|{
literal|"r!"
block|,
literal|"\241"
block|,
comment|/* 161 */
block|}
block|,
block|{
literal|"ct"
block|,
literal|"\242"
block|,
comment|/* 162 */
block|}
block|,
block|{
literal|"Po"
block|,
literal|"\243"
block|,
comment|/* 163 */
block|}
block|,
block|{
literal|"Cs"
block|,
literal|"\244"
block|,
comment|/* 164 */
block|}
block|,
block|{
literal|"Ye"
block|,
literal|"\245"
block|,
comment|/* 165 */
block|}
block|,
block|{
literal|"bb"
block|,
literal|"\246"
block|,
comment|/* 166 */
block|}
block|,
block|{
literal|"sc"
block|,
literal|"\247"
block|,
comment|/* 167 */
block|}
block|,
block|{
literal|"ad"
block|,
literal|"\250"
block|,
comment|/* 168 */
block|}
block|,
block|{
literal|"co"
block|,
literal|"\251"
block|,
comment|/* 169 */
block|}
block|,
block|{
literal|"Of"
block|,
literal|"\252"
block|,
comment|/* 170 */
block|}
block|,
block|{
literal|"Fo"
block|,
literal|"\253"
block|,
comment|/* 171 */
block|}
block|,
block|{
literal|"no"
block|,
literal|"\254"
block|,
comment|/* 172 */
block|}
block|,
block|{
literal|"-"
block|,
literal|"hy"
block|,
literal|"\255"
comment|/* 173 */
block|}
block|,
block|{
literal|"rg"
block|,
literal|"\256"
block|,
comment|/* 174 */
block|}
block|,
block|{
literal|"a-"
block|,
literal|"\257"
block|,
comment|/* 175 */
block|}
block|,
block|{
literal|"de"
block|,
literal|"\260"
block|,
comment|/* 176 */
block|}
block|,
block|{
literal|"+-"
block|,
literal|"\261"
block|,
comment|/* 177 */
block|}
block|,
block|{
literal|"S2"
block|,
literal|"\262"
block|,
comment|/* 178 */
block|}
block|,
block|{
literal|"S3"
block|,
literal|"\263"
block|,
comment|/* 179 */
block|}
block|,
block|{
literal|"aa"
block|,
literal|"\264"
block|,
comment|/* 180 */
block|}
block|,
comment|/* Omit *m here; we want *m to match the other greek letters in the    symbol font. */
block|{
literal|"\265"
block|,
comment|/* 181 */
block|}
block|,
block|{
literal|"ps"
block|,
literal|"\266"
block|,
comment|/* 182 */
block|}
block|,
block|{
literal|"pc"
block|,
literal|"\267"
block|,
comment|/* 183 */
block|}
block|,
block|{
literal|"ac"
block|,
literal|"\270"
block|,
comment|/* 184 */
block|}
block|,
block|{
literal|"S1"
block|,
literal|"\271"
block|,
comment|/* 185 */
block|}
block|,
block|{
literal|"Om"
block|,
literal|"\272"
block|,
comment|/* 186 */
block|}
block|,
block|{
literal|"Fc"
block|,
literal|"\273"
block|,
comment|/* 187 */
block|}
block|,
block|{
literal|"14"
block|,
literal|"\274"
block|,
comment|/* 188 */
block|}
block|,
block|{
literal|"12"
block|,
literal|"\275"
block|,
comment|/* 189 */
block|}
block|,
block|{
literal|"34"
block|,
literal|"\276"
block|,
comment|/* 190 */
block|}
block|,
block|{
literal|"r?"
block|,
literal|"\277"
block|,
comment|/* 191 */
block|}
block|,
block|{
literal|"`A"
block|,
literal|"\300"
block|,
comment|/* 192 */
block|}
block|,
block|{
literal|"'A"
block|,
literal|"\301"
block|,
comment|/* 193 */
block|}
block|,
block|{
literal|"^A"
block|,
literal|"\302"
block|,
comment|/* 194 */
block|}
block|,
block|{
literal|"~A"
block|,
literal|"\303"
block|,
comment|/* 195 */
block|}
block|,
block|{
literal|":A"
block|,
literal|"\304"
block|,
comment|/* 196 */
block|}
block|,
block|{
literal|"oA"
block|,
literal|"\305"
block|,
comment|/* 197 */
block|}
block|,
block|{
literal|"AE"
block|,
literal|"\306"
block|,
comment|/* 198 */
block|}
block|,
block|{
literal|",C"
block|,
literal|"\307"
block|,
comment|/* 199 */
block|}
block|,
block|{
literal|"`E"
block|,
literal|"\310"
block|,
comment|/* 200 */
block|}
block|,
block|{
literal|"'E"
block|,
literal|"\311"
block|,
comment|/* 201 */
block|}
block|,
block|{
literal|"^E"
block|,
literal|"\312"
block|,
comment|/* 202 */
block|}
block|,
block|{
literal|":E"
block|,
literal|"\313"
block|,
comment|/* 203 */
block|}
block|,
block|{
literal|"`I"
block|,
literal|"\314"
block|,
comment|/* 204 */
block|}
block|,
block|{
literal|"'I"
block|,
literal|"\315"
block|,
comment|/* 205 */
block|}
block|,
block|{
literal|"^I"
block|,
literal|"\316"
block|,
comment|/* 206 */
block|}
block|,
block|{
literal|":I"
block|,
literal|"\317"
block|,
comment|/* 207 */
block|}
block|,
block|{
literal|"-D"
block|,
literal|"\320"
block|,
comment|/* 208 */
block|}
block|,
block|{
literal|"~N"
block|,
literal|"\321"
block|,
comment|/* 209 */
block|}
block|,
block|{
literal|"`O"
block|,
literal|"\322"
block|,
comment|/* 210 */
block|}
block|,
block|{
literal|"'O"
block|,
literal|"\323"
block|,
comment|/* 211 */
block|}
block|,
block|{
literal|"^O"
block|,
literal|"\324"
block|,
comment|/* 212 */
block|}
block|,
block|{
literal|"~O"
block|,
literal|"\325"
block|,
comment|/* 213 */
block|}
block|,
block|{
literal|":O"
block|,
literal|"\326"
block|,
comment|/* 214 */
block|}
block|,
block|{
literal|"mu"
block|,
literal|"\327"
block|,
comment|/* 215 */
block|}
block|,
block|{
literal|"/O"
block|,
literal|"\330"
block|,
comment|/* 216 */
block|}
block|,
block|{
literal|"`U"
block|,
literal|"\331"
block|,
comment|/* 217 */
block|}
block|,
block|{
literal|"'U"
block|,
literal|"\332"
block|,
comment|/* 218 */
block|}
block|,
block|{
literal|"^U"
block|,
literal|"\333"
block|,
comment|/* 219 */
block|}
block|,
block|{
literal|":U"
block|,
literal|"\334"
block|,
comment|/* 220 */
block|}
block|,
block|{
literal|"'Y"
block|,
literal|"\335"
block|,
comment|/* 221 */
block|}
block|,
block|{
literal|"TP"
block|,
literal|"\336"
block|,
comment|/* 222 */
block|}
block|,
block|{
literal|"ss"
block|,
literal|"\337"
block|,
comment|/* 223 */
block|}
block|,
block|{
literal|"`a"
block|,
literal|"\340"
block|,
comment|/* 224 */
block|}
block|,
block|{
literal|"'a"
block|,
literal|"\341"
block|,
comment|/* 225 */
block|}
block|,
block|{
literal|"^a"
block|,
literal|"\342"
block|,
comment|/* 226 */
block|}
block|,
block|{
literal|"~a"
block|,
literal|"\343"
block|,
comment|/* 227 */
block|}
block|,
block|{
literal|":a"
block|,
literal|"\344"
block|,
comment|/* 228 */
block|}
block|,
block|{
literal|"oa"
block|,
literal|"\345"
block|,
comment|/* 229 */
block|}
block|,
block|{
literal|"ae"
block|,
literal|"\346"
block|,
comment|/* 230 */
block|}
block|,
block|{
literal|",c"
block|,
literal|"\347"
block|,
comment|/* 231 */
block|}
block|,
block|{
literal|"`e"
block|,
literal|"\350"
block|,
comment|/* 232 */
block|}
block|,
block|{
literal|"'e"
block|,
literal|"\351"
block|,
comment|/* 233 */
block|}
block|,
block|{
literal|"^e"
block|,
literal|"\352"
block|,
comment|/* 234 */
block|}
block|,
block|{
literal|":e"
block|,
literal|"\353"
block|,
comment|/* 235 */
block|}
block|,
block|{
literal|"`i"
block|,
literal|"\354"
block|,
comment|/* 236 */
block|}
block|,
block|{
literal|"'i"
block|,
literal|"\355"
block|,
comment|/* 237 */
block|}
block|,
block|{
literal|"^i"
block|,
literal|"\356"
block|,
comment|/* 238 */
block|}
block|,
block|{
literal|":i"
block|,
literal|"\357"
block|,
comment|/* 239 */
block|}
block|,
block|{
literal|"Sd"
block|,
literal|"\360"
block|,
comment|/* 240 */
block|}
block|,
block|{
literal|"~n"
block|,
literal|"\361"
block|,
comment|/* 241 */
block|}
block|,
block|{
literal|"`o"
block|,
literal|"\362"
block|,
comment|/* 242 */
block|}
block|,
block|{
literal|"'o"
block|,
literal|"\363"
block|,
comment|/* 243 */
block|}
block|,
block|{
literal|"^o"
block|,
literal|"\364"
block|,
comment|/* 244 */
block|}
block|,
block|{
literal|"~o"
block|,
literal|"\365"
block|,
comment|/* 245 */
block|}
block|,
block|{
literal|":o"
block|,
literal|"\366"
block|,
comment|/* 246 */
block|}
block|,
block|{
literal|"di"
block|,
literal|"\367"
block|,
comment|/* 247 */
block|}
block|,
block|{
literal|"/o"
block|,
literal|"\370"
block|,
comment|/* 248 */
block|}
block|,
block|{
literal|"`u"
block|,
literal|"\371"
block|,
comment|/* 249 */
block|}
block|,
block|{
literal|"'u"
block|,
literal|"\372"
block|,
comment|/* 250 */
block|}
block|,
block|{
literal|"^u"
block|,
literal|"\373"
block|,
comment|/* 251 */
block|}
block|,
block|{
literal|":u"
block|,
literal|"\374"
block|,
comment|/* 252 */
block|}
block|,
block|{
literal|"'y"
block|,
literal|"\375"
block|,
comment|/* 253 */
block|}
block|,
block|{
literal|"Tp"
block|,
literal|"\376"
block|,
comment|/* 254 */
block|}
block|,
block|{
literal|":y"
block|,
literal|"\377"
block|,
comment|/* 255 */
block|}
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|DviCharNameMap
name|Adobe_Symbol_map
init|=
block|{
literal|"adobe-fontspecific"
block|,
literal|1
block|,
block|{
block|{
literal|0
block|,
comment|/* 0 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 1 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 2 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 3 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 4 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 5 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 6 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 7 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 8 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 9 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 10 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 11 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 12 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 13 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 14 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 15 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 16 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 17 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 18 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 19 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 20 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 21 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 22 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 23 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 24 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 25 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 26 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 27 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 28 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 29 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 30 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 31 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 32 */
block|}
block|,
block|{
literal|"!"
block|,
comment|/* 33 */
block|}
block|,
block|{
literal|"fa"
block|,
comment|/* 34 */
block|}
block|,
block|{
literal|"#"
block|,
literal|"sh"
block|,
comment|/* 35 */
block|}
block|,
block|{
literal|"te"
block|,
comment|/* 36 */
block|}
block|,
block|{
literal|"%"
block|,
comment|/* 37 */
block|}
block|,
block|{
literal|"&"
block|,
comment|/* 38 */
block|}
block|,
block|{
literal|"st"
block|,
comment|/* 39 */
block|}
block|,
block|{
literal|"("
block|,
comment|/* 40 */
block|}
block|,
block|{
literal|")"
block|,
comment|/* 41 */
block|}
block|,
block|{
literal|"**"
block|,
comment|/* 42 */
block|}
block|,
block|{
literal|"+"
block|,
literal|"pl"
block|,
comment|/* 43 */
block|}
block|,
block|{
literal|","
block|,
comment|/* 44 */
block|}
block|,
block|{
literal|"\\-"
block|,
literal|"mi"
block|,
comment|/* 45 */
block|}
block|,
block|{
literal|"."
block|,
comment|/* 46 */
block|}
block|,
block|{
literal|"/"
block|,
literal|"sl"
block|,
comment|/* 47 */
block|}
block|,
block|{
literal|"0"
block|,
comment|/* 48 */
block|}
block|,
block|{
literal|"1"
block|,
comment|/* 49 */
block|}
block|,
block|{
literal|"2"
block|,
comment|/* 50 */
block|}
block|,
block|{
literal|"3"
block|,
comment|/* 51 */
block|}
block|,
block|{
literal|"4"
block|,
comment|/* 52 */
block|}
block|,
block|{
literal|"5"
block|,
comment|/* 53 */
block|}
block|,
block|{
literal|"6"
block|,
comment|/* 54 */
block|}
block|,
block|{
literal|"7"
block|,
comment|/* 55 */
block|}
block|,
block|{
literal|"8"
block|,
comment|/* 56 */
block|}
block|,
block|{
literal|"9"
block|,
comment|/* 57 */
block|}
block|,
block|{
literal|":"
block|,
comment|/* 58 */
block|}
block|,
block|{
literal|";"
block|,
comment|/* 59 */
block|}
block|,
block|{
literal|"<"
block|,
comment|/* 60 */
block|}
block|,
block|{
literal|"="
block|,
literal|"eq"
block|,
comment|/* 61 */
block|}
block|,
block|{
literal|">"
block|,
comment|/* 62 */
block|}
block|,
block|{
literal|"?"
block|,
comment|/* 63 */
block|}
block|,
block|{
literal|"=~"
block|,
comment|/* 64 */
block|}
block|,
block|{
literal|"*A"
block|,
comment|/* 65 */
block|}
block|,
block|{
literal|"*B"
block|,
comment|/* 66 */
block|}
block|,
block|{
literal|"*X"
block|,
comment|/* 67 */
block|}
block|,
block|{
literal|"*D"
block|,
comment|/* 68 */
block|}
block|,
block|{
literal|"*E"
block|,
comment|/* 69 */
block|}
block|,
block|{
literal|"*F"
block|,
comment|/* 70 */
block|}
block|,
block|{
literal|"*G"
block|,
comment|/* 71 */
block|}
block|,
block|{
literal|"*Y"
block|,
comment|/* 72 */
block|}
block|,
block|{
literal|"*I"
block|,
comment|/* 73 */
block|}
block|,
block|{
literal|"+h"
block|,
comment|/* 74 */
block|}
block|,
block|{
literal|"*K"
block|,
comment|/* 75 */
block|}
block|,
block|{
literal|"*L"
block|,
comment|/* 76 */
block|}
block|,
block|{
literal|"*M"
block|,
comment|/* 77 */
block|}
block|,
block|{
literal|"*N"
block|,
comment|/* 78 */
block|}
block|,
block|{
literal|"*O"
block|,
comment|/* 79 */
block|}
block|,
block|{
literal|"*P"
block|,
comment|/* 80 */
block|}
block|,
block|{
literal|"*H"
block|,
comment|/* 81 */
block|}
block|,
block|{
literal|"*R"
block|,
comment|/* 82 */
block|}
block|,
block|{
literal|"*S"
block|,
comment|/* 83 */
block|}
block|,
block|{
literal|"*T"
block|,
comment|/* 84 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 85 */
block|}
block|,
block|{
literal|"ts"
block|,
comment|/* 86 */
block|}
block|,
block|{
literal|"*W"
block|,
comment|/* 87 */
block|}
block|,
block|{
literal|"*C"
block|,
comment|/* 88 */
block|}
block|,
block|{
literal|"*Q"
block|,
comment|/* 89 */
block|}
block|,
block|{
literal|"*Z"
block|,
comment|/* 90 */
block|}
block|,
block|{
literal|"["
block|,
literal|"lB"
block|,
comment|/* 91 */
block|}
block|,
block|{
literal|"tf"
block|,
literal|"3d"
block|,
comment|/* 92 */
block|}
block|,
block|{
literal|"]"
block|,
literal|"rB"
block|,
comment|/* 93 */
block|}
block|,
block|{
literal|"pp"
block|,
comment|/* 94 */
block|}
block|,
block|{
literal|"_"
block|,
comment|/* 95 */
block|}
block|,
block|{
literal|"radicalex"
block|,
comment|/* 96 */
block|}
block|,
block|{
literal|"*a"
block|,
comment|/* 97 */
block|}
block|,
block|{
literal|"*b"
block|,
comment|/* 98 */
block|}
block|,
block|{
literal|"*x"
block|,
comment|/* 99 */
block|}
block|,
block|{
literal|"*d"
block|,
comment|/* 100 */
block|}
block|,
block|{
literal|"*e"
block|,
comment|/* 101 */
block|}
block|,
block|{
literal|"*f"
block|,
comment|/* 102 */
block|}
block|,
block|{
literal|"*g"
block|,
comment|/* 103 */
block|}
block|,
block|{
literal|"*y"
block|,
comment|/* 104 */
block|}
block|,
block|{
literal|"*i"
block|,
comment|/* 105 */
block|}
block|,
block|{
literal|"+f"
block|,
comment|/* 106 */
block|}
block|,
block|{
literal|"*k"
block|,
comment|/* 107 */
block|}
block|,
block|{
literal|"*l"
block|,
comment|/* 108 */
block|}
block|,
block|{
literal|"*m"
block|,
literal|"\265"
block|,
comment|/* 109 */
block|}
block|,
block|{
literal|"*n"
block|,
comment|/* 110 */
block|}
block|,
block|{
literal|"*o"
block|,
comment|/* 111 */
block|}
block|,
block|{
literal|"*p"
block|,
comment|/* 112 */
block|}
block|,
block|{
literal|"*h"
block|,
comment|/* 113 */
block|}
block|,
block|{
literal|"*r"
block|,
comment|/* 114 */
block|}
block|,
block|{
literal|"*s"
block|,
comment|/* 115 */
block|}
block|,
block|{
literal|"*t"
block|,
comment|/* 116 */
block|}
block|,
block|{
literal|"*u"
block|,
comment|/* 117 */
block|}
block|,
block|{
literal|"+p"
block|,
comment|/* 118 */
block|}
block|,
block|{
literal|"*w"
block|,
comment|/* 119 */
block|}
block|,
block|{
literal|"*c"
block|,
comment|/* 120 */
block|}
block|,
block|{
literal|"*q"
block|,
comment|/* 121 */
block|}
block|,
block|{
literal|"*z"
block|,
comment|/* 122 */
block|}
block|,
block|{
literal|"lC"
block|,
literal|"{"
block|,
comment|/* 123 */
block|}
block|,
block|{
literal|"ba"
block|,
literal|"or"
block|,
literal|"|"
block|,
comment|/* 124 */
block|}
block|,
block|{
literal|"rC"
block|,
literal|"}"
block|,
comment|/* 125 */
block|}
block|,
block|{
literal|"ap"
block|,
comment|/* 126 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 127 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 128 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 129 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 130 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 131 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 132 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 133 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 134 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 135 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 136 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 137 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 138 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 139 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 140 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 141 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 142 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 143 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 144 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 145 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 146 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 147 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 148 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 149 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 150 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 151 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 152 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 153 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 154 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 155 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 156 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 157 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 158 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 159 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 160 */
block|}
block|,
block|{
literal|"*U"
block|,
comment|/* 161 */
block|}
block|,
block|{
literal|"fm"
block|,
comment|/* 162 */
block|}
block|,
block|{
literal|"<="
block|,
comment|/* 163 */
block|}
block|,
block|{
literal|"f/"
block|,
comment|/* 164 */
block|}
block|,
block|{
literal|"if"
block|,
comment|/* 165 */
block|}
block|,
block|{
literal|"Fn"
block|,
comment|/* 166 */
block|}
block|,
block|{
literal|"CL"
block|,
comment|/* 167 */
block|}
block|,
block|{
literal|"DI"
block|,
comment|/* 168 */
block|}
block|,
block|{
literal|"HE"
block|,
comment|/* 169 */
block|}
block|,
block|{
literal|"SP"
block|,
comment|/* 170 */
block|}
block|,
block|{
literal|"<>"
block|,
comment|/* 171 */
block|}
block|,
block|{
literal|"<-"
block|,
comment|/* 172 */
block|}
block|,
block|{
literal|"ua"
block|,
literal|"arrowverttp"
comment|/* 173 */
block|}
block|,
block|{
literal|"->"
block|,
comment|/* 174 */
block|}
block|,
block|{
literal|"da"
block|,
literal|"arrowvertbt"
comment|/* 175 */
block|}
block|,
block|{
literal|"de"
block|,
literal|"\260"
block|,
comment|/* 176 */
block|}
block|,
block|{
literal|"+-"
block|,
literal|"\261"
block|,
comment|/* 177 */
block|}
block|,
block|{
literal|"sd"
block|,
comment|/* 178 */
block|}
block|,
block|{
literal|">="
block|,
comment|/* 179 */
block|}
block|,
block|{
literal|"mu"
block|,
literal|"\327"
block|,
comment|/* 180 */
block|}
block|,
block|{
literal|"pt"
block|,
comment|/* 181 */
block|}
block|,
block|{
literal|"pd"
block|,
comment|/* 182 */
block|}
block|,
block|{
literal|"bu"
block|,
comment|/* 183 */
block|}
block|,
block|{
literal|"di"
block|,
literal|"\367"
block|,
comment|/* 184 */
block|}
block|,
block|{
literal|"!="
block|,
comment|/* 185 */
block|}
block|,
block|{
literal|"=="
block|,
comment|/* 186 */
block|}
block|,
block|{
literal|"~="
block|,
literal|"~~"
block|,
comment|/* 187 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 188 */
block|}
block|,
block|{
literal|"arrowvertex"
block|,
comment|/* 189 */
block|}
block|,
block|{
literal|"an"
block|,
comment|/* 190 */
block|}
block|,
block|{
literal|"CR"
block|,
comment|/* 191 */
block|}
block|,
block|{
literal|"Ah"
block|,
comment|/* 192 */
block|}
block|,
block|{
literal|"Im"
block|,
comment|/* 193 */
block|}
block|,
block|{
literal|"Re"
block|,
comment|/* 194 */
block|}
block|,
block|{
literal|"wp"
block|,
comment|/* 195 */
block|}
block|,
block|{
literal|"c*"
block|,
comment|/* 196 */
block|}
block|,
block|{
literal|"c+"
block|,
comment|/* 197 */
block|}
block|,
block|{
literal|"es"
block|,
comment|/* 198 */
block|}
block|,
block|{
literal|"ca"
block|,
comment|/* 199 */
block|}
block|,
block|{
literal|"cu"
block|,
comment|/* 200 */
block|}
block|,
block|{
literal|"sp"
block|,
comment|/* 201 */
block|}
block|,
block|{
literal|"ip"
block|,
comment|/* 202 */
block|}
block|,
block|{
literal|"nb"
block|,
comment|/* 203 */
block|}
block|,
block|{
literal|"sb"
block|,
comment|/* 204 */
block|}
block|,
block|{
literal|"ib"
block|,
comment|/* 205 */
block|}
block|,
block|{
literal|"mo"
block|,
comment|/* 206 */
block|}
block|,
block|{
literal|"nm"
block|,
comment|/* 207 */
block|}
block|,
block|{
literal|"/_"
block|,
comment|/* 208 */
block|}
block|,
block|{
literal|"gr"
block|,
comment|/* 209 */
block|}
block|,
block|{
literal|"rg"
block|,
comment|/* 210 */
block|}
block|,
block|{
literal|"co"
block|,
comment|/* 211 */
block|}
block|,
block|{
literal|"tm"
block|,
comment|/* 212 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 213 */
block|}
block|,
block|{
literal|"sr"
block|,
comment|/* 214 */
block|}
block|,
block|{
literal|"md"
block|,
comment|/* 215 */
block|}
block|,
block|{
literal|"no"
block|,
literal|"\254"
block|,
comment|/* 216 */
block|}
block|,
block|{
literal|"AN"
block|,
comment|/* 217 */
block|}
block|,
block|{
literal|"OR"
block|,
comment|/* 218 */
block|}
block|,
block|{
literal|"hA"
block|,
comment|/* 219 */
block|}
block|,
block|{
literal|"lA"
block|,
comment|/* 220 */
block|}
block|,
block|{
literal|"uA"
block|,
comment|/* 221 */
block|}
block|,
block|{
literal|"rA"
block|,
comment|/* 222 */
block|}
block|,
block|{
literal|"dA"
block|,
comment|/* 223 */
block|}
block|,
block|{
literal|"lz"
block|,
comment|/* 224 */
block|}
block|,
block|{
literal|"la"
block|,
comment|/* 225 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 226 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 227 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 228 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 229 */
block|}
block|,
block|{
literal|"parenlefttp"
block|,
comment|/* 230 */
block|}
block|,
block|{
literal|"parenleftex"
block|,
comment|/* 231 */
block|}
block|,
block|{
literal|"parenleftbt"
block|,
comment|/* 232 */
block|}
block|,
block|{
literal|"bracketlefttp"
block|,
literal|"lc"
block|,
comment|/* 233 */
block|}
block|,
block|{
literal|"bracketleftex"
block|,
comment|/* 234 */
block|}
block|,
block|{
literal|"bracketleftbt"
block|,
literal|"lf"
block|,
comment|/* 235 */
block|}
block|,
block|{
literal|"bracelefttp"
block|,
literal|"lt"
block|,
comment|/* 236 */
block|}
block|,
block|{
literal|"braceleftmid"
block|,
literal|"lk"
block|,
comment|/* 237 */
block|}
block|,
block|{
literal|"braceleftbt"
block|,
literal|"lb"
block|,
comment|/* 238 */
block|}
block|,
block|{
literal|"bracerightex"
block|,
literal|"braceleftex"
block|,
literal|"bv"
block|,
comment|/* 239 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 240 */
block|}
block|,
block|{
literal|"ra"
block|,
comment|/* 241 */
block|}
block|,
block|{
literal|"is"
block|,
comment|/* 242 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 243 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 244 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 245 */
block|}
block|,
block|{
literal|"parenrighttp"
block|,
comment|/* 246 */
block|}
block|,
block|{
literal|"parenrightex"
block|,
comment|/* 247 */
block|}
block|,
block|{
literal|"parenrightbt"
block|,
comment|/* 248 */
block|}
block|,
block|{
literal|"bracketrighttp"
block|,
literal|"rc"
block|,
comment|/* 249 */
block|}
block|,
block|{
literal|"bracketrightex"
block|,
comment|/* 250 */
block|}
block|,
block|{
literal|"bracketrightbt"
block|,
literal|"rf"
block|,
comment|/* 251 */
block|}
block|,
block|{
literal|"bracerighttp"
block|,
literal|"rt"
comment|/* 252 */
block|}
block|,
block|{
literal|"bracerightmid"
block|,
literal|"rk"
comment|/* 253 */
block|}
block|,
block|{
literal|"bracerightbt"
block|,
literal|"rb"
comment|/* 254 */
block|}
block|,
block|{
literal|0
block|,
comment|/* 255 */
block|}
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|load_standard_maps
parameter_list|()
block|{
name|standard_maps_loaded
operator|=
literal|1
expr_stmt|;
name|DviRegisterMap
argument_list|(
operator|&
name|ISO8859_1_map
argument_list|)
expr_stmt|;
name|DviRegisterMap
argument_list|(
operator|&
name|Adobe_Symbol_map
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


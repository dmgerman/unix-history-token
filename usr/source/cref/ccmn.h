begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|tempent
block|{
name|char
modifier|*
name|beg
decl_stmt|;
name|int
name|ct
decl_stmt|;
name|char
name|term
decl_stmt|;
block|}
name|temp
index|[
literal|30
index|]
struct|;
end_struct

begin_decl_stmt
name|char
name|lbuf
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hlevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dlevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xtrn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tp
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|cl
index|[
name|NUMC
index|]
decl_stmt|;
block|}
name|tab
index|[
name|NUMS
index|]
struct|;
end_struct

begin_function_decl
name|int
name|coll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|save
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|out
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|asym
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|asw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csym
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|incl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sk2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tabs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|semi
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|line
index|[
literal|132
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cursl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|curs
index|[
literal|9
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curfl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|curf
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xsw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|only
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cross
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|flag
index|[
literal|8
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|fl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|gch
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|htab
block|{
name|int
name|hsiz
decl_stmt|;
name|int
name|ssiz
decl_stmt|;
name|int
name|nsym
decl_stmt|;
name|int
name|curb
decl_stmt|;
name|int
modifier|*
name|hptr
decl_stmt|;
name|char
modifier|*
name|symt
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|htab
name|itab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|htab
name|xtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipsp
index|[
name|PTRI
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|issp
index|[
name|CHARI
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xpsp
index|[
name|PTRX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|xssp
index|[
name|CHARX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ib1
index|[
literal|259
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ib2
index|[
literal|259
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ibuf1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ibuf2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|order
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ssw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|utmp
decl_stmt|;
end_decl_stmt

end_unit


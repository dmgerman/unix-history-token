begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* These should come from genemit */
end_comment

begin_comment
comment|/* Use __signed__ in case compiling with -traditional.  */
end_comment

begin_typedef
typedef|typedef
name|__signed__
name|char
name|QItype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|QUtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__signed__
name|short
name|int
name|HItype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|HUtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__signed__
name|long
name|int
name|SItype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|SUtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__signed__
name|long
name|long
name|int
name|DItype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|DUtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|SFtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|DFtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|double
name|XFtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|Ptype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Ttype
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|stacktype
block|{
name|QItype
name|QIval
decl_stmt|;
name|QUtype
name|QUval
decl_stmt|;
name|HItype
name|HIval
decl_stmt|;
name|HUtype
name|HUval
decl_stmt|;
name|SItype
name|SIval
decl_stmt|;
name|SUtype
name|SUval
decl_stmt|;
name|DItype
name|DIval
decl_stmt|;
name|DUtype
name|DUval
decl_stmt|;
name|SFtype
name|SFval
decl_stmt|;
name|DFtype
name|DFval
decl_stmt|;
name|XFtype
name|XFval
decl_stmt|;
name|Ptype
name|Pval
decl_stmt|;
name|Ttype
name|Tval
decl_stmt|;
block|}
name|stacktype
typedef|;
end_typedef

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
struct|struct
name|_xFontName
block|{
name|char
name|Registry
index|[
literal|256
index|]
decl_stmt|;
name|char
name|Foundry
index|[
literal|256
index|]
decl_stmt|;
name|char
name|FamilyName
index|[
literal|256
index|]
decl_stmt|;
name|char
name|WeightName
index|[
literal|256
index|]
decl_stmt|;
name|char
name|Slant
index|[
literal|3
index|]
decl_stmt|;
name|char
name|SetwidthName
index|[
literal|256
index|]
decl_stmt|;
name|char
name|AddStyleName
index|[
literal|256
index|]
decl_stmt|;
name|unsigned
name|int
name|PixelSize
decl_stmt|;
name|unsigned
name|int
name|PointSize
decl_stmt|;
name|unsigned
name|int
name|ResolutionX
decl_stmt|;
name|unsigned
name|int
name|ResolutionY
decl_stmt|;
name|char
name|Spacing
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int
name|AverageWidth
decl_stmt|;
name|char
name|CharSetRegistry
index|[
literal|256
index|]
decl_stmt|;
name|char
name|CharSetEncoding
index|[
literal|256
index|]
decl_stmt|;
block|}
name|XFontName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FontNameRegistry
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FontNameFoundry
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FontNameFamilyName
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FontNameWeightName
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|FontNameSlant
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|FontNameSetwidthName
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|FontNameAddStyleName
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|FontNamePixelSize
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|FontNamePointSize
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|FontNameResolutionX
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|FontNameResolutionY
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|FontNameSpacing
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|FontNameAverageWidth
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|FontNameCharSetRegistry
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|FontNameCharSetEncoding
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|SlantRoman
value|"R"
end_define

begin_define
define|#
directive|define
name|SlantItalic
value|"I"
end_define

begin_define
define|#
directive|define
name|SlantOblique
value|"O"
end_define

begin_define
define|#
directive|define
name|SlantReverseItalic
value|"RI"
end_define

begin_define
define|#
directive|define
name|SlantReverseOblique
value|"RO"
end_define

begin_define
define|#
directive|define
name|SpacingMonoSpaced
value|"M"
end_define

begin_define
define|#
directive|define
name|SpacingProportional
value|"P"
end_define

begin_define
define|#
directive|define
name|SpacingCharacterCell
value|"C"
end_define

begin_typedef
typedef|typedef
name|char
name|XFontNameString
index|[
literal|256
index|]
typedef|;
end_typedef

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Severity codes: I information (not an SGML error at all) W warning (an SGML markup error but it knows what you mean) E error C critical (fatal)  Type codes: R resource C ?context/content M minimization Q quantity S syntax D declaration U unsupported feature */
end_comment

begin_struct
struct|struct
block|{
name|char
modifier|*
name|text
decl_stmt|;
name|char
name|severity
decl_stmt|;
name|char
name|type
decl_stmt|;
block|}
name|messages
index|[]
init|=
block|{
comment|/*   0 */
block|{
literal|0
block|}
block|,
comment|/*   1 */
block|{
literal|"%s element not allowed at this point in %s element"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*   2 */
block|{
literal|"%s markup declaration not permitted here; declaration ended"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*   3 */
block|{
literal|"Length of name, number, or token exceeded NAMELEN or LITLEN limit"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*   4 */
block|{
literal|"Non-SGML character ignored"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*   5 */
block|{
literal|"%s end-tag ignored: doesn't end any open element (current is %s)"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*   6 */
block|{
literal|"%s start-tag exceeds open element limit; possible lies from %s on"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*   7 */
block|{
literal|"Start-tag omitted from %s with empty content"
block|,
literal|'E'
block|,
literal|'M'
block|}
block|,
comment|/*   8 */
block|{
literal|"Illegal entity end in markup or delimited text"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*   9 */
block|{
literal|"Incorrect character in markup; markup terminated"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  10 */
block|{
literal|"Data not allowed at this point in %s element"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  11 */
block|{
literal|"No element declaration for %s end-tag GI; end-tag ignored"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  12 */
block|{
literal|"%s name ignored: not a syntactically valid SGML name"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  13 */
block|{
literal|"%s = \"%s\" attribute ignored: not defined for this element"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  14 */
block|{
literal|"%s = \"%s\" attribute value defaulted: invalid character"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  15 */
block|{
literal|"%s = \"%s\" attribute value defaulted: token too long"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*  16 */
block|{
literal|"%s = \"%s\" attribute value defaulted: too many tokens"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  17 */
block|{
literal|"%s = \"%s\" attribute value defaulted: wrong token type"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  18 */
block|{
literal|"%s = \"%s\" attribute value defaulted: token not in group"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  19 */
block|{
literal|"Required %s attribute was not specified; may affect processing"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  20 */
block|{
literal|"%s end-tag implied by %s end-tag; not minimizable"
block|,
literal|'E'
block|,
literal|'M'
block|}
block|,
comment|/*  21 */
block|{
literal|"%s start-tag implied by %s start-tag; not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/*  22 */
block|{
literal|"Possible attributes treated as data because none were defined"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  23 */
block|{
literal|"Duplicate specification occurred for \"%s\"; may affect processing"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  24 */
block|{
literal|"\"%s\" keyword invalid; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  25 */
block|{
literal|"%s = \"%s\" attribute defaulted: empty string not allowed for token"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  26 */
block|{
literal|"Marked section end ignored; not in a marked section"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  27 */
block|{
literal|"Marked section start ignored; %s marked sections open already"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*  28 */
block|{
literal|"One or more parameters missing; declaration ignored"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  29 */
block|{
literal|"\"PUBLIC\" or \"SYSTEM\" required; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  30 */
block|{
literal|"%s element ended prematurely; required %s omitted"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  31 */
block|{
literal|"Entity \"%s\" terminated: could not read file"
block|,
literal|'E'
block|,
literal|'R'
block|}
block|,
comment|/*  32 */
block|{
literal|"Could not open file for entity \"%s\"; entity reference ignored"
block|,
literal|'E'
block|,
literal|'R'
block|}
block|,
comment|/*  33 */
block|{
literal|"Insufficient main memory; unable to continue parsing"
block|,
literal|'C'
block|,
literal|'R'
block|}
block|,
comment|/*  34 */
block|{
literal|"%s entity reference ignored; exceeded open entity limit (%s)"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*  35 */
block|{
literal|"No declaration for entity \"%s\"; reference ignored"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  36 */
block|{
literal|"%s entity reference occurred within own text; reference ignored"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  37 */
block|{
literal|"Entity nesting level out of sync"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  38 */
block|{
literal|"Parameter entity text cannot have %s keyword; keyword ignored"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  39 */
block|{
literal|"%s end-tag implied by %s start-tag; not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/*  40 */
block|{
literal|"Start-tag minimization ignored; element has required attribute"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  41 */
block|{
literal|"Required %s element cannot be excluded from %s element"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  42 */
block|{
literal|"No DOCTYPE declaration; document type is unknown"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  43 */
block|{
literal|"Undefined %1$s start-tag GI was used in DTD; \"%1$s O O ANY\" assumed"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  44 */
block|{
literal|"Invalid character(s) ignored; attempting to resume DOCTYPE subset"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  45 */
block|{
literal|"No declaration for entity \"%s\"; default definition used"
block|,
literal|'I'
block|,
literal|'C'
block|}
block|,
comment|/*  46 */
block|{
literal|"%s end-tag implied by NET delimiter; not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/*  47 */
block|{
literal|"%s end-tag implied by data; not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/*  48 */
block|{
literal|"%s end-tag implied by short start-tag (no GI); not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/*  49 */
block|{
literal|"%s start-tag implied by data; not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/*  50 */
block|{
literal|"%s start-tag implied by short start-tag (no GI); not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/*  51 */
block|{
literal|"Short end-tag (no GI) ignored: no open elements"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  52 */
block|{
literal|"No definition for %1$s document type; \"%1$s O O ANY\" assumed"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  53 */
block|{
literal|"No definition for %1$s implied start-tag; \"%1$s O O ANY\" assumed"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  54 */
block|{
literal|"%s element ended prematurely; required subelement omitted"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  55 */
block|{
literal|"Content model token %s: connectors conflict; first was used"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  56 */
block|{
literal|"Duplicate specification occurred for \"%s\"; duplicate ignored"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  57 */
block|{
literal|"Bad end-tag in R/CDATA element; treated as short (no GI) end-tag"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  58 */
block|{
literal|"Start-tag minimization should be \"-\" for element with declared content"
block|,
literal|'I'
block|,
literal|'D'
block|}
block|,
comment|/*  59 */
block|{
literal|"Reference to PI entity not permitted here; reference ignored"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  60 */
block|{
literal|"Non-SGML character found; should have been character reference"
block|,
literal|'W'
block|,
literal|'S'
block|}
block|,
comment|/*  61 */
block|{
literal|"Numeric character reference exceeds 255; reference ignored"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  62 */
block|{
literal|"Invalid alphabetic character reference ignored"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  63 */
block|{
literal|"Invalid character in minimum literal; character ignored"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  64 */
block|{
literal|"Keyword %s ignored; \"%s\" is not a valid marked section keyword"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  65 */
block|{
literal|"Parameter entity name longer than (NAMELEN-1); truncated"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*  66 */
block|{
literal|"Start-tag length exceeds TAGLEN limit; parsed correctly"
block|,
literal|'W'
block|,
literal|'Q'
block|}
block|,
comment|/*  67 */
block|{
literal|"%s attribute defaulted: FIXED attribute must equal default"
block|,
literal|'W'
block|,
literal|'C'
block|}
block|,
comment|/*  68 */
block|{
literal|"Duplicate specification occurred for \"%s\"; duplicate ignored"
block|,
literal|'I'
block|,
literal|'D'
block|}
block|,
comment|/*  69 */
block|{
literal|"%s = \"%s\" IDREF attribute ignored: referenced ID does not exist"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  70 */
block|{
literal|"%s = \"%s\" IDREF attribute ignored: number of IDs in list exceeds GRPCNT limit"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*  71 */
block|{
literal|"%s = \"%s\" ID attribute ignored: ID in use for another element"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  72 */
block|{
literal|"%s = \"%s\" ENTITY attribute not general entity; may affect processing"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  73 */
block|{
literal|"%s = \"%s\" attribute ignored: previously specified in same list"
block|,
literal|'W'
block|,
literal|'C'
block|}
block|,
comment|/*  74 */
block|{
literal|"\"?\" = \"%s\" name token ignored: not in any group in this list"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  75 */
block|{
literal|"Normalized attribute specification length over ATTSPLEN limit"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/*  76 */
block|{
literal|"%s = \"%s\" NOTATION ignored: element content is empty"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  77 */
block|{
literal|"%s = \"%s\" NOTATION undefined: may affect processing"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  78 */
block|{
literal|"Entity \"%2$s\" has undefined notation \"%1$s\""
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  79 */
block|{
literal|"%s = \"%s\" default attribute value not in group; #IMPLIED used"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  80 */
block|{
literal|"#CURRENT default value treated as #IMPLIED for %s ID attribute"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  81 */
block|{
literal|"ID attribute %s cannot have a default value; treated as #IMPLIED"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  82 */
block|{
literal|"%s attribute must be token, not empty string; treated as #IMPLIED"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  83 */
block|{
literal|"NOTATION attribute ignored for EMPTY element"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  84 */
block|{
literal|"%s = \"%s\" NOTATION ignored: content reference specified"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  85 */
block|{
literal|"#CONREF default value treated as #IMPLIED for EMPTY element"
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/*  86 */
block|{
literal|"%s = \"%s\" entity not data entity; may affect processing"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  87 */
block|{
literal|"End-tag minimization should be \"O\" for EMPTY element"
block|,
literal|'I'
block|,
literal|'D'
block|}
block|,
comment|/*  88 */
block|{
literal|"Formal public identifier \"%s\" invalid; treated as informal"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/*  89 */
block|{
literal|"Out-of-context %2$s start-tag ended %1$s document element (and parse)"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  90 */
block|{
literal|"\"%s\" keyword is for unsupported feature; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  91 */
block|{
literal|"Attribute specification list in prolog cannot be empty"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  92 */
block|{
literal|"Document ended invalidly within a literal; parsing ended"
block|,
literal|'C'
block|,
literal|'S'
block|}
block|,
comment|/*  93 */
block|{
literal|"General entity \"%s\" in short reference map \"%s\" undeclared"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  94 */
block|{
literal|"Could not reopen file to continue entity \"%s\"; entity terminated"
block|,
literal|'E'
block|,
literal|'R'
block|}
block|,
comment|/*  95 */
block|{
literal|"Out-of-context data ended %s document element (and parse)"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  96 */
block|{
literal|"Short start-tag (no GI) ended %s document element (and parse)"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/*  97 */
block|{
literal|"DSO delimiter (%s) omitted from marked section declaration"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  98 */
block|{
literal|"Group token %s: duplicate name or name token \"%s\" ignored"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/*  99 */
block|{
literal|"Attempt to redefine %s attribute ignored"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 100 */
block|{
literal|"%s definition ignored: %s is not a valid declared value keyword"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 101 */
block|{
literal|"%s definition ignored: NOTATION attribute already defined"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 102 */
block|{
literal|"%s definition ignored: ID attribute already defined"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 103 */
block|{
literal|"%s definition ignored: no declared value specified"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 104 */
block|{
literal|"%s definition ignored: invalid declared value specified"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 105 */
block|{
literal|"%s definition ignored: number of names or name tokens in group exceeded GRPCNT limit"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 106 */
block|{
literal|"%s definition ignored: name group omitted for NOTATION attribute"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 107 */
block|{
literal|"#CONREF default value treated as #IMPLIED for %s ID attribute"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 108 */
block|{
literal|"%s definition ignored: %s is not a valid default value keyword"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 109 */
block|{
literal|"%s definition ignored: no default value specified"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 110 */
block|{
literal|"%s definition ignored: invalid default value specified"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 111 */
block|{
literal|"More than ATTCNT attribute names and/or name (token) values; terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 112 */
block|{
literal|"Attempted redefinition of attribute definition list ignored"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 113 */
block|{
literal|"Content model token %s: more than GRPCNT model group tokens; terminated"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 114 */
block|{
literal|"Content model token %s: more than GRPGTCNT content model tokens; terminated"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 115 */
block|{
literal|"Content model token %s: more than GRPLVL nested model groups; terminated"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 116 */
block|{
literal|"Content model token %s: %s invalid; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 117 */
block|{
literal|"\"PUBLIC\" specified without public ID; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 118 */
block|{
literal|"\"%s\" keyword invalid (only %s permitted); declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 119 */
block|{
literal|"\"%s\" specified without notation name; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 120 */
block|{
literal|"Parameter must be a name; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 121 */
block|{
literal|"Parameter must be a GI or a group of them; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 122 */
block|{
literal|"Parameter must be a name or PERO (%%); declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 123 */
block|{
literal|"Parameter must be a literal; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 124 */
block|{
literal|"\"%s\" not valid short reference delimiter; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 125 */
block|{
literal|"Map does not exist; declaration ignored"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 126 */
block|{
literal|"MDC delimiter (>) expected; following text may be misinterpreted"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 127 */
block|{
literal|"Document ended invalidly within prolog; parsing ended"
block|,
literal|'C'
block|,
literal|'S'
block|}
block|,
comment|/* 128 */
block|{
literal|"\"PUBLIC\" or \"SYSTEM\" or DSO ([) required; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 129 */
block|{
literal|"Minimization must be \"-\" or \"O\" (not \"%s\"); declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 130 */
block|{
literal|"Content model or keyword expected; declaration terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 131 */
block|{
literal|"Rank stem \"%s\" + suffix \"%s\" more than NAMELEN characters; not defined"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 132 */
block|{
literal|"Undefined %s start-tag GI ignored; not used in DTD"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 133 */
block|{
literal|"Document ended invalidly within a markup declaration; parsing ended"
block|,
literal|'C'
block|,
literal|'S'
block|}
block|,
comment|/* 134 */
block|{
literal|"Normalized length of literal exceeded %s; markup terminated"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 135 */
block|{
literal|"R/CDATA marked section in declaration subset; prolog terminated"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 136 */
block|{
literal|"%s = \"%s\" ENTITIES attribute ignored: more than GRPCNT in list"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 137 */
block|{
literal|"Content model is ambiguous"
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/* 138 */
block|{
literal|"Invalid parameter entity name \"%s\""
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/* 139 */
block|{
literal|"Document ended invalidly within a marked section; parsing ended"
block|,
literal|'C'
block|,
literal|'S'
block|}
block|,
comment|/* 140 */
block|{
literal|"Element \"%s\" used in DTD but not defined"
block|,
literal|'I'
block|,
literal|'D'
block|}
block|,
comment|/* 141 */
block|{
literal|"Invalid NDATA or SUBDOC entity reference occurred; ignored"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/* 142 */
block|{
literal|"Associated element type not allowed in document instance"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 143 */
block|{
literal|"Illegal DSC character; in different entity from DSO"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 144 */
block|{
literal|"Declared value of data attribute cannot be ID"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 145 */
block|{
literal|"Invalid reference to external CDATA or SDATA entity; ignored"
block|,
literal|'E'
block|,
literal|'S'
block|}
block|,
comment|/* 146 */
block|{
literal|"Could not find external document type \"%s\""
block|,
literal|'E'
block|,
literal|'R'
block|}
block|,
comment|/* 147 */
block|{
literal|"Could not find external general entity \"%s\""
block|,
literal|'I'
block|,
literal|'R'
block|}
block|,
comment|/* 148 */
block|{
literal|"Could not find external parameter entity \"%s\""
block|,
literal|'I'
block|,
literal|'R'
block|}
block|,
comment|/* 149 */
block|{
literal|"Reference to non-existent general entity \"%s\" ignored"
block|,
literal|'E'
block|,
literal|'R'
block|}
block|,
comment|/* 150 */
block|{
literal|"Could not find entity \"%s\" using default declaration"
block|,
literal|'I'
block|,
literal|'R'
block|}
block|,
comment|/* 151 */
block|{
literal|"Could not find entity \"%2$s\" in attribute %1$s using default declaration"
block|,
literal|'E'
block|,
literal|'R'
block|}
block|,
comment|/* 152 */
block|{
literal|"Short reference map \"%s\" used in USEMAP declaration but not defined; declaration will be ignored"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 153 */
block|{
literal|"End-tag minimization should be \"O\" for element with CONREF attribute"
block|,
literal|'I'
block|,
literal|'D'
block|}
block|,
comment|/* 154 */
block|{
literal|"Declared value of data attribute cannot be ENTITY or ENTITIES"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 155 */
block|{
literal|"Declared value of data attribute cannot be IDREF or IDREFS"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 156 */
block|{
literal|"Declared value of data attribute cannot be NOTATION"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 157 */
block|{
literal|"CURRENT cannot be specified for a data attribute"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 158 */
block|{
literal|"CONREF cannot be specified for a data attribute"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 159 */
block|{
literal|"Parameter must be a number or CONTROLS or NONE"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 160 */
block|{
literal|"Cannot create temporary file"
block|,
literal|'C'
block|,
literal|'R'
block|}
block|,
comment|/* 161 */
block|{
literal|"Document ended invalidly within SGML declaration"
block|,
literal|'C'
block|,
literal|'D'
block|}
block|,
comment|/* 162 */
block|{
literal|"Capacity limit %s exceeded by %s points"
block|,
literal|'W'
block|,
literal|'Q'
block|}
block|,
comment|/* 163 */
block|{
literal|"Amendment 1 requires \"ISO 8879:1986\" instead of \"ISO 8879-1986\""
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/* 164 */
block|{
literal|"Non-markup, non-minimum data character in SGML declaration"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 165 */
block|{
literal|"Parameter cannot be a literal"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 166 */
block|{
literal|"Invalid concrete syntax scope \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 167 */
block|{
literal|"Parameter must be a number"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 168 */
block|{
literal|"\"%s\" should have been \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 169 */
block|{
literal|"Character number %s is not supported as an additional name character"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 170 */
block|{
literal|"Parameter must be a literal or \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 171 */
block|{
literal|"Bad character description for character %s"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 172 */
block|{
literal|"Character number %s is described more than once"
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/* 173 */
block|{
literal|"Character number plus number of characters exceeds 256"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 174 */
block|{
literal|"No description for upper half of character set: assuming \"128 128 UNUSED\""
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/* 175 */
block|{
literal|"Character number %s was not described; assuming UNUSED"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 176 */
block|{
literal|"Non-significant shunned character number %s not declared UNUSED"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 177 */
block|{
literal|"Significant character \"%s\" cannot be non-SGML"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 178 */
block|{
literal|"Unknown capacity set \"%s\""
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 179 */
block|{
literal|"No capacities specified."
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 180 */
block|{
literal|"Unknown concrete syntax \"%s\""
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 181 */
block|{
literal|"Character number exceeds 255"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 182 */
block|{
literal|"Concrete syntax SWITCHES not supported"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 183 */
block|{
literal|"\"INSTANCE\" scope not supported"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 184 */
block|{
literal|"Value of \"%s\" feature must be one or more"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 185 */
block|{
literal|"\"%s\" invalid; must be \"YES\" or \"NO\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 186 */
block|{
literal|"\"%s\" invalid; must be \"PUBLIC\" or \"SGMLREF\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 187 */
block|{
literal|"Feature \"%s\" is not supported"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 188 */
block|{
literal|"Too many open subdocument entities"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 189 */
block|{
literal|"Invalid formal public identifier"
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/* 190 */
block|{
literal|"Public text class must be \"%s\""
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/* 191 */
block|{
literal|"Use of character number %s as an SGML character is not supported"
block|,
literal|'W'
block|,
literal|'U'
block|}
block|,
comment|/* 192 */
block|{
literal|"Notation \"%s\" not defined in DTD"
block|,
literal|'W'
block|,
literal|'D'
block|}
block|,
comment|/* 193 */
block|{
literal|"Unclosed start or end tag requires \"SHORTTAG YES\""
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/* 194 */
block|{
literal|"Net-enabling start tag requires \"SHORTTAG YES\""
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/* 195 */
block|{
literal|"Attribute name omission requires \"SHORTTAG YES\""
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/* 196 */
block|{
literal|"Undelimited attribute value requires \"SHORTTAG YES\""
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/* 197 */
block|{
literal|"Attribute specification omitted for \"%s\": requires markup minimization"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/* 198 */
block|{
literal|"Concrete syntax does not have any short reference delimiters"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 199 */
block|{
literal|"Character number %s not in the base character set; assuming UNUSED"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 200 */
block|{
literal|"Character number %s is UNUSED in the syntax reference character set"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 201 */
block|{
literal|"Character number %s was not described in the syntax reference character set"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 202 */
block|{
literal|"Character number %s in the syntax reference character set has no corresponding character in the system character set"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 203 */
block|{
literal|"Character number %s was described using an unknown base set"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 204 */
block|{
literal|"Duplication specification for added function \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 205 */
block|{
literal|"Added function character cannot be \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 206 */
block|{
literal|"Only reference concrete syntax function characters supported"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 207 */
block|{
literal|"Only reference concrete syntax general delimiters supported"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 208 */
block|{
literal|"Only reference concrete syntax short reference delimiters supported"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 209 */
block|{
literal|"Unrecognized keyword \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 210 */
block|{
literal|"Unrecognized quantity name \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 211 */
block|{
literal|"Interpretation of \"%s\" is not a valid name in the declared concrete syntax"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 212 */
block|{
literal|"Replacement reserved name \"%s\" cannot be reference reserved name"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 213 */
block|{
literal|"Duplicate replacement reserved name \"%s\""
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 214 */
block|{
literal|"Quantity \"%s\" must not be less than %s"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 215 */
block|{
literal|"Only values up to %2$s are supported for quantity \"%1$s\""
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 216 */
block|{
literal|"%s element cannot be excluded from %s element because it is neither inherently optional nor a member of an or group"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 217 */
block|{
literal|"Marked section not allowed in other prolog"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 218 */
block|{
literal|"Required %s attribute was not specified for entity %s"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 219 */
block|{
literal|"UCNMSTRT must have the same number of characters as LCNMSTRT"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 220 */
block|{
literal|"UCNMCHAR must have the same number of characters as LCNMCHAR"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 221 */
block|{
literal|"Character number %s assigned to both LCNMSTRT or UCNMSTRT and LCNMCHAR or UCNMCHAR"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 222 */
block|{
literal|"Character number %s cannot be an additional name character"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 223 */
block|{
literal|"It is unsupported for \"-\" not to be assigned to UCNMCHAR or LCNMCHAR"
block|,
literal|'E'
block|,
literal|'U'
block|}
block|,
comment|/* 224 */
block|{
literal|"Normalized length of value of attribute \"%s\" exceeded LITLEN"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 225 */
block|{
literal|"Length of interpreted parameter literal exceeds LITLEN less the length of the bracketing delimiters"
block|,
literal|'E'
block|,
literal|'Q'
block|}
block|,
comment|/* 226 */
block|{
literal|"Start tag of document element omitted; not minimizable"
block|,
literal|'W'
block|,
literal|'M'
block|}
block|,
comment|/* 227 */
block|{
literal|"Unrecognized designating escape sequence \"%s\""
block|,
literal|'I'
block|,
literal|'U'
block|}
block|,
comment|/* 228 */
block|{
literal|"Earlier reference to entity \"%s\" used default entity"
block|,
literal|'I'
block|,
literal|'D'
block|}
block|,
comment|/* 229 */
block|{
literal|"Reference to non-existent parameter entity \"%s\" ignored"
block|,
literal|'E'
block|,
literal|'R'
block|}
block|,
comment|/* 230 */
block|{
literal|"DSC within marked section; marked section terminated"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 231 */
block|{
literal|"Document element end tag can only occur in document element because entity end not allowed in other prolog"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 232 */
block|{
literal|"Character reference not allowed in other prolog"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 233 */
block|{
literal|"USEMAP declaration not allowed in other prolog"
block|,
literal|'E'
block|,
literal|'D'
block|}
block|,
comment|/* 234 */
block|{
literal|"Entity reference not allowed in other prolog"
block|,
literal|'E'
block|,
literal|'C'
block|}
block|,
comment|/* 235 */
block|{
literal|"Value assigned to capacity %s exceeds value assigned to TOTALCAP"
block|,
literal|'W'
block|,
literal|'D'
block|}
block|, }
struct|;
end_struct

end_unit


#!/bin/bash

set -e

CONFIG=$(cat <<EOF
{
Language:        Cpp,
BasedOnStyle:  LLVM,
AccessModifierOffset: -2,
AlignAfterOpenBracket: true,
AlignEscapedNewlinesLeft: false,
AlignOperands:   false,
AlignTrailingComments: true,
AllowAllParametersOfDeclarationOnNextLine: true,
AllowShortBlocksOnASingleLine: false,
AllowShortCaseLabelsOnASingleLine: false,
AllowShortIfStatementsOnASingleLine: false,
AllowShortLoopsOnASingleLine: false,
AllowShortFunctionsOnASingleLine: All,
AlwaysBreakAfterDefinitionReturnType: false,
AlwaysBreakTemplateDeclarations: false,
AlwaysBreakBeforeMultilineStrings: false,
BreakBeforeBinaryOperators: None,
BreakBeforeTernaryOperators: false,
BreakConstructorInitializersBeforeComma: false,
BinPackParameters: true,
BinPackArguments: true,
ColumnLimit:     80,
ConstructorInitializerAllOnOneLineOrOnePerLine: false,
ConstructorInitializerIndentWidth: 4,
DerivePointerAlignment: false,
ExperimentalAutoDetectBinPacking: false,
IndentCaseLabels: false,
IndentWrappedFunctionNames: false,
IndentFunctionDeclarationAfterType: false,
MaxEmptyLinesToKeep: 1,
KeepEmptyLinesAtTheStartOfBlocks: true,
NamespaceIndentation: None,
ObjCBlockIndentWidth: 2,
ObjCSpaceAfterProperty: false,
ObjCSpaceBeforeProtocolList: true,
PenaltyBreakBeforeFirstCallParameter: 19,
PenaltyBreakComment: 300,
PenaltyBreakString: 1000,
PenaltyBreakFirstLessLess: 120,
PenaltyExcessCharacter: 1000000,
PenaltyReturnTypeOnItsOwnLine: 60,
PointerAlignment: Middle,
SpacesBeforeTrailingComments: 1,
Cpp11BracedListStyle: true,
Standard:        Cpp11,
IndentWidth:     2,
TabWidth:        8,
UseTab:          Never,
BreakBeforeBraces: Allman,
SpacesInParentheses: false,
SpacesInSquareBrackets: false,
SpacesInAngles:  false,
SpaceInEmptyParentheses: false,
SpacesInCStyleCastParentheses: false,
SpaceAfterCStyleCast: false,
SpacesInContainerLiterals: true,
SpaceBeforeAssignmentOperators: true,
ContinuationIndentWidth: 4,
CommentPragmas:  '^',
ForEachMacros:   [ foreach, Q_FOREACH, BOOST_FOREACH ],
SpaceBeforeParens: ControlStatements,
DisableFormat:   false
}
EOF
)

CONFIG=$(echo "$CONFIG" | tr '\n' ' ' | sed s/" "\\+/" "/g)

for file in $@
do
    formatted_file=`mktemp`
    clang-format-3.6 -style="$CONFIG" $file  > $formatted_file
    diff --minimal --side-by-side -W 170 $file $formatted_file | cat -v > $file.diff
    rm $formatted_file
done

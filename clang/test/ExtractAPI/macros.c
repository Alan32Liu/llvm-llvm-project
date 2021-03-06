// RUN: rm -rf %t
// RUN: split-file %s %t
// RUN: sed -e "s@INPUT_DIR@%/t@g" %t/reference.output.json.in >> \
// RUN: %t/reference.output.json
// RUN: %clang -extract-api --product-name=Macros -target arm64-apple-macosx \
// RUN: -x objective-c-header %t/input.h -o %t/output.json | FileCheck -allow-empty %s

// Generator version is not consistent across test runs, normalize it.
// RUN: sed -e "s@\"generator\": \".*\"@\"generator\": \"?\"@g" \
// RUN: %t/output.json >> %t/output-normalized.json
// RUN: diff %t/reference.output.json %t/output-normalized.json

// CHECK-NOT: error:
// CHECK-NOT: warning:

//--- input.h
#define HELLO 1
#define WORLD 2
#define MACRO_FUN(x) x x
#define FUN(x, y, z) x + y + z
#define FUNC99(x, ...)
#define FUNGNU(x...)

//--- reference.output.json.in
{
  "metadata": {
    "formatVersion": {
      "major": 0,
      "minor": 5,
      "patch": 3
    },
    "generator": "?"
  },
  "module": {
    "name": "Macros",
    "platform": {
      "architecture": "arm64",
      "operatingSystem": {
        "minimumVersion": {
          "major": 11,
          "minor": 0,
          "patch": 0
        },
        "name": "macosx"
      },
      "vendor": "apple"
    }
  },
  "relationhips": [],
  "symbols": [
    {
      "declarationFragments": [
        {
          "kind": "keyword",
          "spelling": "#define"
        },
        {
          "kind": "text",
          "spelling": " "
        },
        {
          "kind": "identifier",
          "spelling": "HELLO"
        }
      ],
      "identifier": {
        "interfaceLanguage": "objective-c",
        "precise": "c:input.h@8@macro@HELLO"
      },
      "kind": {
        "displayName": "Macro",
        "identifier": "objective-c.macro"
      },
      "location": {
        "character": 9,
        "line": 1,
        "uri": "file://INPUT_DIR/input.h"
      },
      "names": {
        "subHeading": [
          {
            "kind": "identifier",
            "spelling": "HELLO"
          }
        ],
        "title": "HELLO"
      }
    },
    {
      "declarationFragments": [
        {
          "kind": "keyword",
          "spelling": "#define"
        },
        {
          "kind": "text",
          "spelling": " "
        },
        {
          "kind": "identifier",
          "spelling": "WORLD"
        }
      ],
      "identifier": {
        "interfaceLanguage": "objective-c",
        "precise": "c:input.h@24@macro@WORLD"
      },
      "kind": {
        "displayName": "Macro",
        "identifier": "objective-c.macro"
      },
      "location": {
        "character": 9,
        "line": 2,
        "uri": "file://INPUT_DIR/input.h"
      },
      "names": {
        "subHeading": [
          {
            "kind": "identifier",
            "spelling": "WORLD"
          }
        ],
        "title": "WORLD"
      }
    },
    {
      "declarationFragments": [
        {
          "kind": "keyword",
          "spelling": "#define"
        },
        {
          "kind": "text",
          "spelling": " "
        },
        {
          "kind": "identifier",
          "spelling": "MACRO_FUN"
        },
        {
          "kind": "text",
          "spelling": "("
        },
        {
          "kind": "internalParam",
          "spelling": "x"
        },
        {
          "kind": "text",
          "spelling": ")"
        }
      ],
      "identifier": {
        "interfaceLanguage": "objective-c",
        "precise": "c:input.h@40@macro@MACRO_FUN"
      },
      "kind": {
        "displayName": "Macro",
        "identifier": "objective-c.macro"
      },
      "location": {
        "character": 9,
        "line": 3,
        "uri": "file://INPUT_DIR/input.h"
      },
      "names": {
        "subHeading": [
          {
            "kind": "identifier",
            "spelling": "MACRO_FUN"
          }
        ],
        "title": "MACRO_FUN"
      }
    },
    {
      "declarationFragments": [
        {
          "kind": "keyword",
          "spelling": "#define"
        },
        {
          "kind": "text",
          "spelling": " "
        },
        {
          "kind": "identifier",
          "spelling": "FUN"
        },
        {
          "kind": "text",
          "spelling": "("
        },
        {
          "kind": "internalParam",
          "spelling": "x"
        },
        {
          "kind": "text",
          "spelling": ", "
        },
        {
          "kind": "internalParam",
          "spelling": "y"
        },
        {
          "kind": "text",
          "spelling": ", "
        },
        {
          "kind": "internalParam",
          "spelling": "z"
        },
        {
          "kind": "text",
          "spelling": ")"
        }
      ],
      "identifier": {
        "interfaceLanguage": "objective-c",
        "precise": "c:input.h@65@macro@FUN"
      },
      "kind": {
        "displayName": "Macro",
        "identifier": "objective-c.macro"
      },
      "location": {
        "character": 9,
        "line": 4,
        "uri": "file://INPUT_DIR/input.h"
      },
      "names": {
        "subHeading": [
          {
            "kind": "identifier",
            "spelling": "FUN"
          }
        ],
        "title": "FUN"
      }
    },
    {
      "declarationFragments": [
        {
          "kind": "keyword",
          "spelling": "#define"
        },
        {
          "kind": "text",
          "spelling": " "
        },
        {
          "kind": "identifier",
          "spelling": "FUNC99"
        },
        {
          "kind": "text",
          "spelling": "("
        },
        {
          "kind": "internalParam",
          "spelling": "x"
        },
        {
          "kind": "text",
          "spelling": ", ...)"
        }
      ],
      "identifier": {
        "interfaceLanguage": "objective-c",
        "precise": "c:input.h@96@macro@FUNC99"
      },
      "kind": {
        "displayName": "Macro",
        "identifier": "objective-c.macro"
      },
      "location": {
        "character": 9,
        "line": 5,
        "uri": "file://INPUT_DIR/input.h"
      },
      "names": {
        "subHeading": [
          {
            "kind": "identifier",
            "spelling": "FUNC99"
          }
        ],
        "title": "FUNC99"
      }
    },
    {
      "declarationFragments": [
        {
          "kind": "keyword",
          "spelling": "#define"
        },
        {
          "kind": "text",
          "spelling": " "
        },
        {
          "kind": "identifier",
          "spelling": "FUNGNU"
        },
        {
          "kind": "text",
          "spelling": "("
        },
        {
          "kind": "internalParam",
          "spelling": "x"
        },
        {
          "kind": "text",
          "spelling": "...)"
        }
      ],
      "identifier": {
        "interfaceLanguage": "objective-c",
        "precise": "c:input.h@119@macro@FUNGNU"
      },
      "kind": {
        "displayName": "Macro",
        "identifier": "objective-c.macro"
      },
      "location": {
        "character": 9,
        "line": 6,
        "uri": "file://INPUT_DIR/input.h"
      },
      "names": {
        "subHeading": [
          {
            "kind": "identifier",
            "spelling": "FUNGNU"
          }
        ],
        "title": "FUNGNU"
      }
    }
  ]
}

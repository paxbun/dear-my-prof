{
    "targets": [{
        "target_name": "dear-my-prof-bind",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "Source/Bind.cpp"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "../core/Public"
        ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        'conditions': [
            ['OS=="win"', {
                'libraries': [
                    "../../core/build/dear-my-prof-core.lib"
                ]
            }],
            ['OS!="win"', {
                'libraries': [
                    "../../core/build/libdear-my-prof-core.a"
                ],
                'cflags': [
                    '-Wl,--whole-archive'
                ]
            }]
        ]
    }]
}
{
    'targets': [{
        'target_name': 'dear-my-prof-bind',
        'cflags!': [ '-fno-exceptions' ],
        'cflags_cc!': [ '-fno-exceptions' ],
        'sources': [
            $SOURCES$
        ],
        'include_dirs': [
            $INCLUDE_DIRS$
        ],
        'dependencies': [
            $DEP_GYP$
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        'conditions': [
            ['OS=="win"', {
                'libraries': [
                    "$LIBRARY_DIR$/dear-my-prof-core.lib"
                ]
            }],
            ['OS!="win"', {
                'libraries': [
                    "$LIBRARY_DIR$/libdear-my-prof-core.a"
                ],
                'cflags': [
                    '-Wl,--whole-archive'
                ]
            }]
        ]
    }]
}
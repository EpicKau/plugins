<?php

/*
    Copyright (C) 2018 Michael Muenz <m.muenz@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
    AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
    OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

function bind_enabled()
{
    $model = new \OPNsense\Bind\General();
    return (string)$model->enabled == '1';
}

function bind_services()
{
    $services = array();

    if (!bind_enabled()) {
        return $services;
    }

    $services[] = array(
        'description' => gettext('BIND Daemon'),
        'configd' => array(
            'restart' => array('bind restart'),
            'start' => array('bind start'),
            'stop' => array('bind stop'),
        ),
        'name' => 'named',
        'pidfile' => '/var/run/named/pid'
    );

    return $services;
}

function bind_xmlrpc_sync()
{
    $result = array();
    $result['id'] = 'bind';
    $result['section'] = 'OPNsense.bind';
    $result['description'] = gettext('BIND domain name service');
    return array($result);
}

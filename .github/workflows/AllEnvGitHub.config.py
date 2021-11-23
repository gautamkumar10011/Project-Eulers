echo "HOME: ${HOME}"
echo "HOME: ${HOME}"
echo "CI : ${CI}"
echo "GITHUB_WORKFLOW : ${GITHUB_WORKFLOW}"
echo "GITHUB_RUN_ID : ${GITHUB_RUN_ID}"
echo "GITHUB_RUN_NUMBER : ${GITHUB_RUN_NUMBER}"
echo "GITHUB_JOB : ${GITHUB_JOB}"
echo "GITHUB_ACTION : ${GITHUB_ACTION}"
echo "GITHUB_ACTION_PATH : ${GITHUB_ACTION_PATH}"
echo "GITHUB_ACTIONS : ${GITHUB_ACTIONS}"
echo "GITHUB_ACTOR : ${GITHUB_ACTOR}"
echo "GITHUB_REPOSITORY : ${GITHUB_REPOSITORY}"
echo "GITHUB_EVENT_NAME : ${GITHUB_EVENT_NAME}"
echo "GITHUB_EVENT_PATH : ${GITHUB_EVENT_PATH}"
echo "GITHUB_WORKSPACE : ${GITHUB_WORKSPACE}"
echo "GITHUB_SHA : ${GITHUB_SHA}"
echo "GITHUB_REF : ${GITHUB_REF}"
echo "GITHUB_REF_NAME : ${GITHUB_REF_NAME}"
echo "GITHUB_REF_PROTECTED : ${GITHUB_REF_PROTECTED}"
echo "GITHUB_REF_TYPE : ${GITHUB_REF_TYPE}"
echo "GITHUB_HEAD_REF : ${GITHUB_HEAD_REF}"
echo "GITHUB_BASE_REF : ${GITHUB_BASE_REF}"
echo "GITHUB_SERVER_URL : ${GITHUB_SERVER_URL}"
echo "GITHUB_API_URL : ${GITHUB_API_URL}"
echo "GITHUB_GRAPHQL_URL : ${GITHUB_GRAPHQL_URL}"
echo "RUNNER_NAME : ${RUNNER_NAME}"
echo "RUNNER_OS : ${RUNNER_OS}"
echo "RUNNER_TEMP : ${RUNNER_TEMP}"
echo "RUNNER_TOOL_CACHE : ${RUNNER_TOOL_CACHE}"
====================================================================
====================================================================

  shell: /usr/bin/bash -e {0}
  env:
    WF_ENV: Available to all jobs
    WF_SECRET_ENV: ***

====================================================================
====================================================================
HOME: /home/runner
CI : true
GITHUB_WORKFLOW : ENV VARIABLES
GITHUB_RUN_ID : 1493765163
GITHUB_RUN_NUMBER : 6
GITHUB_JOB : log-default-env
GITHUB_ACTION : __run
GITHUB_ACTION_PATH : 
GITHUB_ACTIONS : true
GITHUB_ACTOR : gautamkumar10011
GITHUB_REPOSITORY : gautamkumar10011/Project-Eulers
GITHUB_EVENT_NAME : push
GITHUB_EVENT_PATH : /home/runner/work/_temp/_github_workflow/event.json
GITHUB_WORKSPACE : /home/runner/work/Project-Eulers/Project-Eulers
GITHUB_SHA : d62fdc7642a9cfba4046d51d0f66d6917ec2f4ac
GITHUB_REF : refs/heads/master
GITHUB_REF_NAME : master
GITHUB_REF_PROTECTED : false
GITHUB_REF_TYPE : branch
GITHUB_HEAD_REF : 
GITHUB_BASE_REF : 
GITHUB_SERVER_URL : https://github.com
GITHUB_API_URL : https://api.github.com
GITHUB_GRAPHQL_URL : https://api.github.com/graphql
RUNNER_NAME : Hosted Agent
RUNNER_OS : Linux
RUNNER_TEMP : /home/runner/work/_temp
RUNNER_TOOL_CACHE : /opt/hostedtoolcache
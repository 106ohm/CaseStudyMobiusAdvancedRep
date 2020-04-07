# ***
# environment to compile and run the mobius project: DSN2020ToolMobius26
# ***
FROM mobius:2.5

# Change to the root user.
USER root

ARG DEBIAN_FRONTEND=noninteractive

# builder
COPY --from=builder:latest /usr /usr

# mobius projects dir
ARG MOBIUS_PROJECT=/usr/local/home/mobius/MobiusProject

# the project name
ARG PROJECTNAME=DSN2020ToolCaseStudyMobius26

# the project dir
ARG THEPROJECT=$MOBIUS_PROJECT/$PROJECTNAME

# working dir
WORKDIR $MOBIUS_PROJECT

# Change to the mobius user.
USER mobius

# copy Mobius project
COPY --chown=mobius:mobius . $THEPROJECT

# update license file
COPY License-2.6.mli /usr/share/mobius-2.5/License.mli
COPY --chown=mobius:mobius License-2.6.mli /home/giulio/git/mobius/edu.illinois.mobius.cpp/License.mli

# the curr dir: the project
WORKDIR $THEPROJECT

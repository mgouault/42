FROM ubuntu

RUN apt-get -qq update && apt-get -qq -y install openssh-server && useradd mgouault
RUN chmod 777 /home && sudo -u mgouault mkdir -p /home/mgouault/.ssh && sudo -u mgouault touch /home/mgouault/.ssh/authorized_keys && chmod 700 /home/mgouault/.ssh && chmod 600 /home/mgouault/.ssh/authorized_keys
RUN echo "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQC/VATgN/k48Z7HALgFxfdNzdA6eO8EPeths4J/4bTlBR7VzBbaP2VF30hc3aw1jZNV6/zXZrJ3za+MME/ekQGlRJbVWQstay/7jBW7wOf2cBtCWLruMkmHntFgfvg8xLZCAJUs2by8uW+sBKBGXZ+PrS79VmgPls7NY9LxGqdD5Va30faTCqgy7f6UnCsuxHsT4RvaCwA2JL7JZWRgMOPdut3ynzJGMJVEjJG8SMG8bLr/S2zZZIPG35dq2chHnMGep1qeuQwwgcd0ZtbVSJy/WH8QcwRwWhIAePnt1evNZgmBZq/UnCLFKDh8zEamAfmbZx9Sr3dDl8L8vZm9ytHd mgouault@e2r8p16.42.fr" > /tmp/id_rsa.pub
RUN cat /tmp/id_rsa.pub > /home/mgouault/.ssh/authorized_keys && rm /tmp/id_rsa.pub
RUN sed -i 's/Port 22/Port 42/g' /etc/ssh/sshd_config

CMD /etc/init.d/ssh start -d
